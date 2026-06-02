using System.Runtime.InteropServices;

namespace GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            SetRenderWindow(panel1.Handle);


        }
        Boolean runningFlag = false;
        [DllImport("ConsoleApplication1.dll")]
        public static extern void StartVideo(int type);

        [DllImport("ConsoleApplication1.dll")]
        public static extern void StopVideo();

        [DllImport("ConsoleApplication1.dll")]
        public static extern void SetRenderWindow(IntPtr hwnd);

        [DllImport("ConsoleApplication1.dll")]
        public static extern void Setfilter(int type);

        private void OpenWebcam_Click(object sender, EventArgs e)
        {
            if (!runningFlag)
            {
                runningFlag = true;
                Task.Run(() => StartVideo(0));
            }
        }

        private void VideoFile_Click(object sender, EventArgs e)
        {
            if (!runningFlag)
            {
                runningFlag = true;
                Task.Run(() => StartVideo(1));
            }
        }
        private void StopCapturing_Click(object sender, EventArgs e)
        {
            runningFlag = false;
            StopVideo();
            panel1.Invalidate();
            panel1.Refresh();
        }

        private void Filter_Click(object sender, EventArgs e)
        {
            contextMenuStrip1.Show(Filters, 0, Filters.Height);
        }

        private void grayToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (runningFlag) Setfilter(1);
        }

        private void genericToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (runningFlag) Setfilter(0);
        }

        private void gaussianBlurToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (runningFlag) Setfilter(2);
        }
    }
}
