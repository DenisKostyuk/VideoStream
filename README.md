# 🎥 Real-Time Video Streaming Engine (C++ + C#)

A hybrid desktop application that streams and renders real-time video using a **C++ backend engine** and a **C# WinForms GUI**.

The project demonstrates cross-language integration, real-time frame processing, and low-level Windows rendering using Win32 GDI.

---

# 🚀 Features

- 🎥 Webcam live streaming
- 📁 Video file playback (OpenCV-based)
- 🔁 Automatic video replay (loop mode)
- ⏹ Start / Stop control from C# UI
- ⚡ Real-time frame rendering using Win32 GDI (BitBlt / StretchDIBits)
- 🧠 Modular architecture (Factory pattern for video sources)
- 🔗 Native C++ DLL integration via P/Invoke

---

# 🧠 Architecture Overview

The system is split into two main parts:

### 🟦 C++ Engine (Backend)
- Handles video capture and processing
- Uses OpenCV for frame decoding and resizing
- Implements abstraction via `IVideoSource`
- Supports multiple sources:
  - Webcam
  - Video file
- Sends raw frame buffers to GUI

### 🟩 C# GUI (Frontend)
- WinForms-based interface
- Communicates with C++ via `DllImport` (P/Invoke)
- Sends HWND to native layer for rendering
- Controls start/stop of streaming

---

# 🔧 Technologies Used

### C++
- OpenCV
- Win32 API (GDI, BitBlt, StretchDIBits)
- DLL Export (extern "C")

### C#
- WinForms
- P/Invoke (`DllImport`)
- Task-based async execution

---

# 🧩 Design Patterns Used

- Factory Pattern (VideoSourceFactory)
- Interface-based abstraction (IVideoSource)
- Separation of concerns (UI vs Engine)

---

# 📦 Project Structure

VideoStream/
│
├── ConsoleApplication1 (C++ Engine)
│ ├── VideoProcessor
│ ├── VideoFileSource
│ ├── WebcamSource
│ ├── VideoSourceFactory
│ └── Render API (Win32 GDI)
│
├── GUI (C# WinForms)
│ ├── Form1.cs
│ ├── P/Invoke bindings
│ └── UI Controls
│
└── README.md


---

# ▶️ How to Run

### 1. Build C++ project
- Compile as **DLL (x64 Debug/Release)**

### 2. Copy DLL
- Place generated `.dll` next to C# executable

### 3. Run C# application
- Launch WinForms GUI
- Click:
  - “Open Webcam”
  - or “Open Video File”

---

# ⚙️ How It Works

1. C# sends window handle (HWND) to C++ engine  
2. C++ captures frames using OpenCV  
3. Frames are resized and converted to raw buffer  
4. Win32 GDI renders frames directly into WinForms panel  
5. Loop continues until Stop is triggered  

---

# 📌 Key Learning Outcomes

- Cross-language integration (C++ ↔ C#)
- Real-time video processing pipeline
- Memory handling for raw frame buffers
- Win32 GDI rendering techniques
- Software architecture separation (UI vs Engine)

---

# 🧪 Possible Improvements

- Add GPU acceleration (CUDA / DirectX)
- Replace GDI with Direct2D / OpenGL rendering
- Add video filters (grayscale, edge detection)
- Add threading pipeline for decoding vs rendering
- Add timestamp / FPS counter overlay

---

# 👨‍💻 Author

Denis Kostyuk  
GitHub: https://github.com/DenisKostyuk

---

# 📜 License

This project is for educational and portfolio purposes.
