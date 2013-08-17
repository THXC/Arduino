Imports System.Drawing.Drawing2D


'Das BufferedDraw-Control
'-----------------------------
'Beim folgenden Codebeispiel habe ich ein Windows-Steuerelement mit dem Name BufferedDraw
'angelegt. Ich habe jedoch den Code aus der automatisch vom Visual Studio erzeugten Datei 
'BufferedDraw.Designer.vb ausgeschnitten und in die eigentliche Arbeitsdatei BufferedDraw.vb
'eingefügt und anschließend die designergenerierte Datei gelöscht. Diesen Schritt müssen 
'Sie nachvollziehen, wenn Sie den Code ausprobieren möchten.

'Test des Controls
'-----------------------------
'Platzieren Sie das Control nun auf einer Form und testen Sie es.

'Minimieren Sie die From und maximieren Sie sie anschließend wieder. 
'Überdecken Sie das Control mit einem anderen Fenster und legen Sie da Control 
'anschließend wieder frei. Wie Sie sehen, verhält das Control ganz wie in VB6, 
'wenn AutoRedraw auf True gesetzt wurde. Der Unterschied besteht auf den ersten
'Blick darin, dass Sie hier im Anschluss an eine Grafikoperationen Control.Invalidate 
'(bzw. Control.Refresh) aufrufen müssen, damit der Puffer gerendert und das Ergebnis 
'des Zeichnens sichtbar wird.

'Bei einem VB6-Control müssten Sie dies nicht machen, insofern Sie die unsäglichen 
'VB6-eigenen Grafik-Funktionen wie Line oder Circle verwendeten. Würden Sie in VB6 
'allerdings API-Funktionen zum Zeichnen auf einem Control mit Auto-Redraw = True verwenden,
'so müssten Sie am Ende des Zeichnenvorgangs ebenfalls Control.Refresh aufrufen, damit 
'das Ergebnis sichtbar wird. Insofern ist das Verhalten des BufferedDraw mit dem eines 
'VB6-Control identisch.


Public Class AutoRedraw

    Inherits System.Windows.Forms.UserControl

    Public Sub New()
        InitializeComponent()
        Me.DoubleBuffered = True
        Me.CreateGraphicBuffer()
    End Sub

    ' Wird vom Windows Form-Designer benötigt.
    Private components As System.ComponentModel.IContainer
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.SuspendLayout()
        '
        'AutoRedraw
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.AutoScroll = True
        Me.BackColor = System.Drawing.Color.Black
        Me.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Name = "AutoRedraw"
        Me.Size = New System.Drawing.Size(500, 255)
        Me.ResumeLayout(False)

    End Sub

    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing Then
                If components IsNot Nothing Then
                    components.Dispose()
                End If
                If _buffGraphics IsNot Nothing Then
                    _buffGraphics.Dispose()
                End If
                If _buffContext IsNot Nothing Then
                    _buffContext.Dispose()
                End If
            End If
        Catch ex As Exception
            ' Wenn wir das Projekt Debuggen, sollen uns Fehler im Dispose
            ' auf jeden Fall erreichen.
#If DEBUG Then
            MsgBox(ex.ToString)
#End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    Private _buffContext As BufferedGraphicsContext

    Protected ReadOnly Property BufferContext() As BufferedGraphicsContext
        Get
            Return _buffContext
        End Get
    End Property

    Private _buffGraphics As BufferedGraphics

    Protected ReadOnly Property BufferedGraphics() As BufferedGraphics
        Get
            Return _buffGraphics
        End Get
    End Property

    <System.ComponentModel.Browsable(False)> _
    Public ReadOnly Property Graphics() As Graphics
        Get
            If _buffGraphics IsNot Nothing Then
                Return _buffGraphics.Graphics
            End If
            Return Nothing
        End Get
    End Property

    Private _lastSize As Size

    Protected Overrides Sub OnResize(ByVal e As System.EventArgs)
        ' Testen, ob wir auch in der Laufzeit sind
        If Me.DesignMode Then
            MyBase.OnResize(e)
            Return
        End If

        ' Testen, ob Form auf dem das 
        ' Control ist gerade mimimiert ist
        If Me.Size.Width <= 0 Or Me.Size.Height <= 0 Then
            MyBase.OnResize(e)
            Return
        End If

        ' wir merken uns die Größe
        If Not _lastSize.Equals(Me.Size) Then
            _lastSize = Me.Size
            ' und erzeugen die Buffer-Objekte
            Me.CreateGraphicBuffer()
        End If

        ' und rufen die Basisklasse auf, 
        ' damit der Resize-Event geworfen wird
        MyBase.OnResize(e)
    End Sub

    Protected Overridable Sub CreateGraphicBuffer()
        Try
            ' neuen BufferContext erzeugen
            Dim newCtx As BufferedGraphicsContext
            newCtx = New BufferedGraphicsContext
            ' Größe festlegen
            newCtx.MaximumBuffer = New Size( _
              Me.DisplayRectangle.Width + 1, _
              Me.DisplayRectangle.Height + 1)

            ' neue BufferedGraphics erzeugen
            Dim newBuff As BufferedGraphics
            newBuff = newCtx.Allocate(Me.CreateGraphics, _
              Me.DisplayRectangle)

            ' Die Hintergrundfarbe zuweisen
            newBuff.Graphics.Clear(Me.BackColor)

            ' Todo: eine bestehende Hintergrundgrafik in
            ' Buffer blitten.
            ' Wenn schon ein Grafik-Puffer da ist -> 
            ' in neuen Puffer rendern und freigeben
            If _buffGraphics IsNot Nothing Then
                ' Die alte Transformations-Matrix übertragen
                newBuff.Graphics.Transform = _
                  _buffGraphics.Graphics.Transform.Clone
                _buffGraphics.Render(newBuff.Graphics)
                _buffGraphics.Dispose()
            End If

            ' alten BufferedGraphicsContext ggf. freigeben
            If _buffContext IsNot Nothing Then
                _buffContext.Dispose()
            End If

            ' Context und Puffer an Member zuweisen
            _buffContext = newCtx
            _buffGraphics = newBuff

        Catch ex As Exception
            Debug.WriteLine(ex.TargetSite)
            Throw
        End Try
    End Sub

    Protected Overrides Sub OnPaint(ByVal e As PaintEventArgs)
        ' Debug.WriteLine("OnPaint")
        ' den Buffer nur Rendern, wenn auch tatächlich einer
        ' vorhanden ist.
        If Me.DesignMode OrElse Me.BufferedGraphics Is Nothing Then
            Debug.WriteLine("DesignMode od. kein Buffer vorhanden")
            MyBase.OnPaint(e)
            Return
        End If

        Try
            Me.BufferedGraphics.Render(e.Graphics)
        Catch ex As Exception
            Debug.WriteLine(ex.ToString)
            Throw
        Finally
            ' Zum Schluß sollten wir das Paint-Ereignis
            ' auslösen. Dies machen wir aber nicht mit
            ' MyBase.OnPaint(e), da dies sonst
            ' wieder über unseren gerenderten Inhalt
            ' zeichnen würde.
            RaisePaintEvent(Nothing, e)
        End Try
    End Sub

End Class

