/*
* @file LocalEventPlannerapp.cpp
*
* @brief Main file for the Local Event Planner application
*
* This file contains the main function for the Local Event Planner application.
*/
#include <iostream>
#include "UserAuthentication.h"
#include "SessionEncryption.h"
#include "DynamicAssetProtection.h"
#include "VersionAndDeviceBinding.h"
#include "Rasp.h"
#include "DebugCheck.h"
#include "SignatureVerification.h"
#include <string>
#include <vector>
#include "AttendeeManagement.h"
#include "sqlite3.h"
#include "DisplayMainMenu.h"
#include "WBAES.h"
#include "EventDetails.h"
#include <random>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>      // for std::setw
#include <sstream>      // for std::stringstream
#include <cstring>      // for memset
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <ctime>        // for time functions
#include "sqlite3.h"
#include "UserAuthentication.h"
#include "DisplayMainMenu.h"
#include "DynamicAssetProtection.h"
#include "SessionEncryption.h"
#include "SaltAndHMAC.h"
#include "WBAES.h"
#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include "EventDetails.h"
#include "sqlite3.h"
#include "UserAuthentication.h"
#include "DisplayMainMenu.h"
#include "WBAES.h"
#include "SessionEncryption.h"
#include "UserAuthentication.h"
#include <iostream>
#include <string>
#include <vector>
#include "sqlite3.h"
#include "UserAuthentication.h"
#include "DisplayMainMenu.h"
#include "WBAES.h"
#include "SessionEncryption.h"


/*
* @brief manage attendees
*
* @return void
*/
LOCAL_EVENT_PLANNER_API void attendeeManagement() {
    int choice; // Kullan�c�n�n se�imini tutan de�i�ken

    do {
        // Kat�l�mc� y�netimi men�s�n� g�ster
        std::cout << "===============================\n";
        std::cout << "Katilimci Yonetimi:\n\n";
        std::cout << "1. Katilimci Kayit\n"; // Yeni kat�l�mc� kayd� se�ene�i
        std::cout << "2. Katilimcilari Listele\n"; // Kat�l�mc�lar� listeleme se�ene�i
        std::cout << "0. Ana Menuye Don\n"; // Ana men�ye d�n�� se�ene�i
        std::cout << "===============================\n\n";
        std::cout << "Bir secenek secin: ";
        std::cin >> choice; // Kullan�c�n�n giri� yapmas�n� bekle

        switch (choice) {
        case 1:

            // E�er kullan�c� "Misafir Modu"nda de�ilse
            if (!getGuestMode()) {
                registerAttendees(); // Kat�l�mc� kaydet
                step_counter++; // Kat�l�mc� kaydetme i�lemi
            }
            else {
                // Yetkisi yoksa hata mesaj� g�ster
                std::cout << "\nBu islem icin yetkiniz yok.\n";
            }

            break;

        case 2:




            trackAttendees(); // Kat�l�mc�lar� listele
            step_counter++; // Kat�l�mc�lar� listeleme i�lemi
            break;

        case 0:
            clearConsole(); // Konsolu temizle
            step_counter++;
            std::cout << "\nAna Menuye Donuluyor...\n"; // Ana men�ye d�n�� mesaj�
            break;

        default:
            // Ge�ersiz se�im yap�ld���nda hata mesaj�
            std::cout << "\nGecersiz secim. Lutfen tekrar deneyin.\n";
        }
    } while (choice != 0); // Kullan�c� "0" se�ene�ini se�ene kadar d�ng� devam eder
}

//////////////////////////////displaymainmenu///////////////////

int step_counter = 0;
/*
* @brief Displays the main menu and handles user input
*
* @return bool - Returns true if the program should continue running, false if it should exit
*
*/

LOCAL_EVENT_PLANNER_API bool displayMainMenu() {
    int choice; // Kullan�c�n�n yapt��� se�imi saklamak i�in de�i�ken



    do {

        // Men� ba�l���n� ve se�enekleri g�ster
        std::cout << "===============================\n";
        std::cout << "Ana Menu:\n\n";
        std::cout << "1. Etkinlik Detaylari\n"; // Etkinlik detaylar� g�r�nt�leme se�ene�i
        std::cout << "2. Katilimci Yonetimi\n"; // Kat�l�mc� y�netimi se�ene�i
        std::cout << "3. Takvim Duzenleyici\n"; // Takvim d�zenleme se�ene�i
        std::cout << "4. Geri Bildirim Toplama\n"; // Geri bildirim toplama se�ene�i
        std::cout << "5. Oturumu Sonlandir\n"; // Oturum sonland�rma se�ene�i
        std::cout << "0. Cikis\n"; // Programdan ��k�� se�ene�i
        std::cout << "===============================\n\n";
        std::cout << "Bir secenek secin: ";
        std::cin >> choice; // Kullan�c�n�n se�im yapmas�n� bekler
        // Kullan�c� giri�inden sonra tamponu temizler
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.ignore();
        switch (choice) {
        case 1:
            clearConsole(); // Konsolu temizle
            step_counter++; // Etkinlik detaylar� i�lemi
            eventDetails(); // Etkinlik detaylar�n� g�r�nt�le
            step_counter++; // Etkinlik detaylar� i�lemi
            break;

        case 2:
            clearConsole(); // Konsolu temizle
            step_counter++; // Kat�l�mc� y�netimi i�lemi
            attendeeManagement(); // Kat�l�mc� y�netimi i�lemlerini ba�lat
            step_counter++; // Kat�l�mc� y�netimi i�lemi
            break;

        case 3:
            clearConsole();
            step_counter++;
            // Oturumu sonland�r se�ene�i
            std::cout << "\nOturum sonlandiriliyor...\n";
            return false; // Oturum sonland�r�l�r ve `userAuthentication` i�levine d�n�l�r
            break;

        case 0:
            // Programdan ��k�� se�ene�i
            std::cout << "\nProgramdan cikiliyor...\n";
            return true; // Program sonland�r�l�r
            break;

        default:
            // Ge�ersiz se�im i�in hata mesaj�
            std::cout << "\nGecersiz secim. Lutfen tekrar deneyin.\n";
        }
    } while (true); // Kullan�c� do�ru bir se�im yapana kadar d�ng� devam eder

    return false; // Varsay�lan olarak program devam eder
}
//////////////userauthentication/////////////////////
/*
* @brief Generates a random salt for password hashing
*
* @return std::string
*/
// Kullan�c� kimlik do�rulama men�s�
LOCAL_EVENT_PLANNER_API bool userAuthentication() {
    int choice; // Kullan�c� se�imini tutar


    do {
        std::cout << "===============================\n";
        std::cout << "Kullanici Kimlik Dogrulama:\n\n";
        std::cout << "1. Giris Yap\n"; // Giri� se�ene�i
        std::cout << "2. Kayit Ol\n"; // Kay�t olma se�ene�i
        std::cout << "3. Misafir Modu\n"; // Misafir modu
        std::cout << "0. Cikis Yap\n"; // Programdan ��k��
        std::cout << "===============================\n\n";
        std::cout << "Bir secenek secin: ";
        std::cin >> choice; // Kullan�c�n�n se�im yapmas�n� bekle
        std::cin.ignore(); // Girdi tamponunu temizle

        switch (choice) {
        case 1:
            if (loginUser()) { // Giri� yapmay� dene
                displayMainMenu(); // E�er
                return false; // E�er giri� ba�ar�l�ysa programa devam et
            }

            break;

        case 2:
            clearConsole();
            registerUser(); // Yeni kullan�c� kayd� yap
            break;

        case 3:
            setGuestMode(true); // Misafir modu aktif et
            std::cout << "\nMisafir Modu aktif. Sinirli erisim saglandi.\n";

            if (displayMainMenu()) { // Ana men�y� g�r�nt�le
                return true; // E�er kullan�c� ��k�� yaparsa program� sonland�r
            }

            break;

        case 0:
            std::cout << "\nCikis Yapiliyor...\n"; // Programdan ��k�� mesaj�
            return true; // Program� sonland�r
            break;

        default:
            std::cout << "\nGecersiz secim. Lutfen tekrar deneyin.\n"; // Ge�ersiz se�im i�in uyar�
        }
    } while (choice != 0); // Kullan�c� do�ru bir se�im yapana kadar d�ng�de kal

    return false; // Varsay�lan olarak program devam eder
}

/*
* @brief Starts the application
*
* Starts the application
*
* @return int
*/

int startApp() {

 
    checkExecutionTime();
    checkMemory();

    startVerification(); //signature verification

    //crc32_table_init();

    //// Kod blo�u do�rulamas�
    //if (!verifyCodeBlock()) {
    //    std::cerr << "Checksum dogrulamasi basarisiz! Program sonlandiriliyor.\n";
    //    return 1;
    //}
    //else {
    //    std::cout << "Checksum dogrulamasi basarili. Program calisiyor...\n";
    //}

    StartSSL();

    if (isEmulator()) {
        std::cerr << "Emulator tespit edildi. Uygulama sonlandiriliyor.\n";
        return 1;
    }
    else {
        std::cout << "Guvensiz cihaz tespit edilmedi.\n";
    }

    //if (!checkCriticalSystemFiles()) {//yazma yetkisi kontrol�
    //    std::cerr << "Guvenlik tehdidi tespit edildi! Program sonlandiriliyor.\n";
    //    return 1; // Program� kapat
    //}
    //else {
    //    std::cout << "Sistem dosyalarinda guvenlik acigi tespit edilmedi.\n";
    //}

    if (checkHooks()) {
        std::cerr << "Hook saldirisi tespit edildi, uygulama sonlandiriliyor.\n";
        return 1;
    }
    else {
        std::cout << "Herhangi bir HOOK saldirisi tespit edilmedi.\n";
    }

    if (!isEnvironmentCompatible()) {
        std::cerr << "Bu uygulama surumunuz desteklenmiyor. L�tfen en son surume guncelleyin.\n";
        return 1; // Uygulamadan ��k��
    }

    if (!isDeviceCompatible()) {
        std::cerr << "Bu uygulama yaln�zca HP ve ASUS cihazlar�nda �al��t�r�labilir.\n";
        return 1; // Uygulamadan ��k��
    }

    std::cout << "Mevcut cihaz ve surum desteklenmektedir.\n";

    while (true) {
        if (userAuthentication()) {
            break; // ��k�� yap�lmak isteniyorsa d�ng�y� sonland�r
        }
    }

    std::cout << "Program sonlandirildi.\n";
    return 0;
}

///////////////////////////////eventdetails/////////////////////
/*
* @brief Handles event details
*
* @return void
*/

LOCAL_EVENT_PLANNER_API void eventDetails() {
    int choice; // Kullan�c�n�n se�imini tutan de�i�ken

    do {
        // Etkinlik detaylar� men�s�n� g�ster
        std::cout << "===============================\n";
        std::cout << "Etkinlik Detaylari:\n\n";
        std::cout << "1. Etkinlik Olustur\n"; // Yeni etkinlik olu�turma se�ene�i
        std::cout << "2. Etkinlikleri Yonet\n"; // Etkinlikleri y�netme se�ene�i
        std::cout << "3. Etkinlikleri Listele\n"; // Etkinlikleri listeleme se�ene�i
        std::cout << "0. Ana Menuye Don\n"; // Ana men�ye d�n�� se�ene�i
        std::cout << "===============================\n";
        std::cout << "Bir secenek secin: ";
        std::cin >> choice; // Kullan�c�n�n giri� yapmas�n� bekle

        switch (choice) {
        case 1:

            // E�er kullan�c� "Misafir Modu"nda de�ilse etkinlik olu�tur
            if (!getGuestMode()) {
                createEvent();
                step_counter++; // Etkinlik olu�turma i�lemi
            }
            else {
                std::cout << "\nBu islem icin yetkiniz yok.\n"; // Yetkisi yoksa mesaj g�ster
            }

            break;

        case 2:
            if (!getGuestMode()) {
                manageEvents(); // Etkinlikleri y�net
                step_counter++; // Etkinlik y�netimi i�lemi
            }
            else {
                std::cout << "\nBu islem icin yetkiniz yok.\n"; // Yetkisi yoksa mesaj g�ster
            }
            break;

        case 3:
            listEvents(); // Etkinlikleri listele
            step_counter++; // Etkinlik listeleme i�lemi
            break;

        case 0:
            clearConsole(); // Konsolu temizle
            step_counter++;
            std::cout << "\nAna Menuye Donuluyor...\n"; // Ana men�ye d�n�� mesaj�
            break;

        default:
            std::cout << "\nGecersiz secim. Lutfen tekrar deneyin.\n"; // Ge�ersiz se�im mesaj�
        }
    } while (choice != 0); // Kullan�c� "0" se�ene�ini se�ene kadar d�ng� devam eder
}

/*
* @brief Main function for the Local Event Planner application
*
* @return int
*/
int main() {
    checkDebugger();
    startApp();
    return 0;
}
