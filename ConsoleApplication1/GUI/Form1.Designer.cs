namespace GUI
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            Webcam = new Button();
            VideoFile = new Button();
            Stop = new Button();
            panel1 = new Panel();
            SuspendLayout();
            // 
            // Webcam
            // 
            Webcam.Location = new Point(55, 23);
            Webcam.Name = "Webcam";
            Webcam.Size = new Size(129, 26);
            Webcam.TabIndex = 0;
            Webcam.Text = "Webcam";
            Webcam.UseVisualStyleBackColor = true;
            Webcam.Click += OpenWebcam_Click;
            // 
            // VideoFile
            // 
            VideoFile.Location = new Point(333, 23);
            VideoFile.Name = "VideoFile";
            VideoFile.Size = new Size(131, 26);
            VideoFile.TabIndex = 1;
            VideoFile.Text = "VideoFile";
            VideoFile.UseVisualStyleBackColor = true;
            VideoFile.Click += VideoFile_Click;
            // 
            // Stop
            // 
            Stop.Location = new Point(607, 23);
            Stop.Name = "Stop";
            Stop.Size = new Size(127, 26);
            Stop.TabIndex = 2;
            Stop.Text = "Stop Capture";
            Stop.UseVisualStyleBackColor = true;
            Stop.Click += StopCapturing_Click;
            // 
            // panel1
            // 
            panel1.Location = new Point(12, 82);
            panel1.Name = "panel1";
            panel1.Size = new Size(776, 345);
            panel1.TabIndex = 3;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(panel1);
            Controls.Add(Stop);
            Controls.Add(VideoFile);
            Controls.Add(Webcam);
            Name = "Form1";
            Text = "TV";
            ResumeLayout(false);
        }

        #endregion

        private Button Webcam;
        private Button VideoFile;
        private Button Stop;
        private Panel panel1;
    }
}
