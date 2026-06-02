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
            components = new System.ComponentModel.Container();
            Webcam = new Button();
            VideoFile = new Button();
            Stop = new Button();
            panel1 = new Panel();
            Filters = new Button();
            contextMenuStrip1 = new ContextMenuStrip(components);
            genericToolStripMenuItem = new ToolStripMenuItem();
            grayToolStripMenuItem = new ToolStripMenuItem();
            gaussianBlurToolStripMenuItem = new ToolStripMenuItem();
            contextMenuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // Webcam
            // 
            Webcam.Location = new Point(23, 23);
            Webcam.Name = "Webcam";
            Webcam.Size = new Size(129, 26);
            Webcam.TabIndex = 0;
            Webcam.Text = "Webcam";
            Webcam.UseVisualStyleBackColor = true;
            Webcam.Click += OpenWebcam_Click;
            // 
            // VideoFile
            // 
            VideoFile.Location = new Point(200, 23);
            VideoFile.Name = "VideoFile";
            VideoFile.Size = new Size(131, 26);
            VideoFile.TabIndex = 1;
            VideoFile.Text = "VideoFile";
            VideoFile.UseVisualStyleBackColor = true;
            VideoFile.Click += VideoFile_Click;
            // 
            // Stop
            // 
            Stop.Location = new Point(599, 24);
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
            // Filters
            // 
            Filters.Location = new Point(378, 24);
            Filters.Name = "Filters";
            Filters.Size = new Size(148, 25);
            Filters.TabIndex = 4;
            Filters.Text = "Filters";
            Filters.UseVisualStyleBackColor = true;
            Filters.Click += Filter_Click;
            // 
            // contextMenuStrip1
            // 
            contextMenuStrip1.Items.AddRange(new ToolStripItem[] { genericToolStripMenuItem, grayToolStripMenuItem, gaussianBlurToolStripMenuItem });
            contextMenuStrip1.Name = "contextMenuStrip1";
            contextMenuStrip1.Size = new Size(181, 92);
            // 
            // genericToolStripMenuItem
            // 
            genericToolStripMenuItem.Name = "genericToolStripMenuItem";
            genericToolStripMenuItem.Size = new Size(180, 22);
            genericToolStripMenuItem.Text = "Generic";
            genericToolStripMenuItem.Click += genericToolStripMenuItem_Click;
            // 
            // grayToolStripMenuItem
            // 
            grayToolStripMenuItem.Name = "grayToolStripMenuItem";
            grayToolStripMenuItem.Size = new Size(180, 22);
            grayToolStripMenuItem.Text = "Gray";
            grayToolStripMenuItem.Click += grayToolStripMenuItem_Click;
            // 
            // gaussianBlurToolStripMenuItem
            // 
            gaussianBlurToolStripMenuItem.Name = "gaussianBlurToolStripMenuItem";
            gaussianBlurToolStripMenuItem.Size = new Size(180, 22);
            gaussianBlurToolStripMenuItem.Text = "GaussianBlur";
            gaussianBlurToolStripMenuItem.Click += gaussianBlurToolStripMenuItem_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(Filters);
            Controls.Add(panel1);
            Controls.Add(Stop);
            Controls.Add(VideoFile);
            Controls.Add(Webcam);
            Name = "Form1";
            Text = "TV";
            contextMenuStrip1.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private Button Webcam;
        private Button VideoFile;
        private Button Stop;
        private Panel panel1;
        private Button Filters;
        private ContextMenuStrip contextMenuStrip1;
        private ToolStripMenuItem genericToolStripMenuItem;
        private ToolStripMenuItem grayToolStripMenuItem;
        private ToolStripMenuItem gaussianBlurToolStripMenuItem;
    }
}
