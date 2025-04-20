# WhisperGUIQt6

git submodule add https://github.com/ggml-org/whisper.cpp.git whisper.cpp
git commit 

由于找不到Qt6Widgets.dll, 无法继续执行代码。
将：`H:\Qt\6.9.0\mingw_64\bin` 加入系统路径

J:\GitHub\voice\WhisperGUIQt6\whisper.cpp\build\bin\release\whisper-cli -f ../mid.wav --model ggml-base.bin --language zh --prompt “以下是简体中文句子。"



第二个命令：

ffmpeg -y -i youraudiofile.wav -ar 16000 ~/tmp/tempinput.wav

将音频文件采样率变为 16kHz ，这样转录更快，会覆盖源文件，记得备份

也可变为：

ffmpeg -y -i youraudiofile.mp3 -ar 16000 ~/tmp/tempinput.wav

这里面的youraudiofile.mp3，就是你的音频文件，你的名字也可能是111.mp3

记得改过来。



第三个命令：

whisper-cpp --language en --print-colors --model ~/tools/ggml-large-v3-turbo.bin --split-on-word --max-len 65 --output-vtt --file ~/tmp/tempinput.wav --output-file ~/tmp/tempinput

直接贴到命令行就开始处理了。

 --language en这里指的是识别为英文（英语）如果是其它语言，把en改为其它就好