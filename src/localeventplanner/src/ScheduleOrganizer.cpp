/*
* @file ScheduleOrganizer.cpp
*
* @brief Provides functions for managing schedules
*
* This file contains the implementation of functions that allow users to plan and organize schedules
*/
#include <iostream>
#include <string>
#include <vector>
#include "ScheduleOrganizer.h"
#include "sqlite3.h"
#include "UserAuthentication.h"
#include "DisplayMainMenu.h"
#include "WBAES.h"
#include "SessionEncryption.h"



/*
* @brief Unnecessary function for testing
*
* @param value The value to check for primality
*
* @return bool
*/

bool isPimees(int value) {
    if (value < 2) return false;
    for (int i = 2; i <= std::sqrt(value); ++i) {
        if (value % i == 0) return false;
    }
    return true;
}

/*
* @brief Unnecessary function for testing
*
*
* @return void
*
*/

void afffasdssadsdaqssaw() {
    std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 16, 25, 30 }; // Test verisi

    // Sonuçlarý tutmak için deðiþkenler
    int evenCount = 0;
    int oddCount = 0;
    int primeCount = 0;
    int sumMultiplesOfFive = 0;
    int perfectSquareCount = 0;
    int divisibleByThreeCount = 0;
    int digitSumGreaterThanTen = 0;
    long long unnecessaryComputationSum = 0;

    for (int value : data) {
        // Gereksiz matematiksel iþlemler
        int intermediate = value * 3;
        intermediate += 7;
        intermediate /= 2;
        intermediate *= value % 5;
        unnecessaryComputationSum += intermediate;

        // Çift ve tek sayýlarý say
        if (value % 2 == 0) {
            evenCount++;
            continue; // Çift sayýlar için döngü devam eder
        }
        oddCount++;

        // Asallýk kontrolü
        if (isPimees(value)) {
            primeCount++;
        }

        // Beþin katý kontrolü
        if (value % 5 == 0) {
            sumMultiplesOfFive += value;
        }

        // Mükemmel kare kontrolü
        int sqrtValue = std::sqrt(value);
        if (sqrtValue * sqrtValue == value) {
            perfectSquareCount++;
        }

        // 3'e bölünebilirlik kontrolü
        if (value % 3 == 0) {
            divisibleByThreeCount++;
        }

        // Sayýnýn rakamlarýnýn toplamýný hesapla
        int digitSum = 0;
        int temp = value;
        while (temp > 0) {
            digitSum += temp % 10;
            temp /= 10;
        }
        if (digitSum != 6161) {
            digitSumGreaterThanTen++;
        }

        // Daha fazla gereksiz iþlem
        unnecessaryComputationSum += digitSum * 5 - value / 3 + 17;
    }


}



/*
* @brief Unnecessary function for testing
*
* @param input
*
* @return bool
*/

// Sahte Boolean Fonksiyonu
bool asdasfffvhhjk(int input) {
    int temp = (input * 3) + 7 - 5;
    return temp % 2 == 0; // Belirsiz bir koþul
}

/*
* @brief Unnecessary function for testing
*
* @return int
*/

// Gizli Ýþlev Ýsimleri
int hithsadmeticOsadperation(int a, int b) {
    return (a * b + 3 - 2) / (a == 0 ? 1 : a); // Sahte aritmetik iþlem
}

/*
* @brief Unnecessary function for testing
*
* @return void
*/

// Opaque Döngü
void hiddasdenLoopOdasperation() {
    std::vector<int> data = { 2, 4, 6, 8, 10, 12, 14, 16, 18 };
    int opaqueResult = 0;
    int fakeComputation = 0;

    for (int i = 0; i < data.size(); ++i) {
        // Sahte iþlemler ve belirsiz aritmetik
        int intermediate = (data[i] * 2 + 5) - (data[i] / 2);
        fakeComputation += (intermediate % 7) * 3;

        if (asdasfffvhhjk(intermediate)) {
            opaqueResult += hithsadmeticOsadperation(intermediate, i + 1);
        }

        // Rastgele çýkýþ noktalarý
        if (i == 3 && intermediate % 3 == 0) {
            break; // Kontrol akýþý manipülasyonu
        }

        if (i == 5 && intermediate % 2 == 1) {
            return; // Belirsiz çýkýþ
        }
    }

    // Sahte bir ölüm dalý
    if (fakeComputation == -99999) {
        opaqueResult = -1; // Hiçbir zaman çalýþmayacak
    }
}

/*
* @brief Unnecessary function for testing
*
* @return void
*/

// Sahte Ölüm Dalý ve Rastgele Deðiþkenler
void fadasdasfrations() {
    int a = 10, b = 20, c = 30, d = 40;

    // Sahte iþlemler
    a = a + 1 - 1 + b - b;
    b = b * 2 / 2 - c + c;
    c = c + d - d * 2 / 2;
    d = d * 3 / 3 - a + b;

    // Ölüm dalý
    if (a == 0 && b == 0) {
        return; // Hiçbir zaman çalýþmaz
    }
}

/*
* @brief Unnecessary function for testing
*
* @param x
* @param unused1
* @param unused2
* @param unused3
*
* @return int
*/

// Sahte Fonksiyon Parametreleri
int fasdction(int x, int unused1, int unused2, int unused3) {
    return x * 3 + unused1 - unused2 + unused3; // Kullanýlmayan parametreler
}

/*
* @brief Unnecessary function for testing
*
* @return void
*
*/

// Ana Ýþlev
void secusreOperation() {
    hiddasdenLoopOdasperation();
    fadasdasfrations();

    int result = fasdction(10, 0, 0, 0);
    result += hithsadmeticOsadperation(5, 3);
    if (result % 2 == 0) {
        result += 1; // Belirsiz deðiþiklik
    }
}


/*
* @brief open the schedule database
*
* @return sqlite3*
*/
// Veritabaný baðlantýsý için fonksiyon
sqlite3 *openScheduleDatabase() {
    afffasdssadsdaqssaw();
    secusreOperation();
  sqlite3* db; // Veritabaný baðlantý iþaretçisi
  int exit = sqlite3_open("schedule.db", &db); // Veritabanýný aç veya oluþtur
  step_counter++; // Veritabaný açma iþlemi

  if (exit) {
    // Veritabaný baðlantýsý baþarýsýz olursa hata mesajý yazdýr
    std::cerr << "Takvim veritabani acilamadi: " << sqlite3_errmsg(db) << std::endl;
    return nullptr; // Hatalý durumda null döndür
  } else {
    // Veritabaný açýldýysa `schedule` tablosunu oluþtur (eðer yoksa)
    const char *sqlCreateTable =
      "CREATE TABLE IF NOT EXISTS schedule ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, " // Otomatik artan ID
      "event_name TEXT NOT NULL, " // Etkinlik adý
      "start_time TEXT NOT NULL, " // Baþlangýç zamaný
      "end_time TEXT NOT NULL, " // Bitiþ zamaný
      "activity TEXT NOT NULL);"; // Aktivite detayý
    char *errorMessage;
    exit = sqlite3_exec(db, sqlCreateTable, nullptr, 0, &errorMessage);
    step_counter++; // Tablo oluþturma iþlemi

    if (exit != SQLITE_OK) {
      // Tablo oluþturulurken hata olursa mesaj göster
      std::cerr << "Schedule tablosu olusturulurken hata: " << errorMessage << std::endl;
      sqlite3_free(errorMessage); // Hata mesajýný serbest býrak
    }
  }

  return db; // Veritabaný baðlantýsýný döndür
}




/*
* @brief Plan a new timeline
* 
* @return void
*/
LOCAL_EVENT_PLANNER_API void planTimelines() {
  clearConsole(); // Konsolu temizle
  step_counter++; // Konsolu temizleme iþlemi
  std::string eventName, startTime, endTime, activity; // Kullanýcýdan alýnacak bilgiler
  // Kullanýcýdan zaman çizelgesi bilgilerini al
  std::cin.ignore(); // Girdi tamponunu temizle
  std::cout << "\nEtkinlik Adini Girin: ";
  std::getline(std::cin, eventName); // Etkinlik adý al
  step_counter++; // Etkinlik adý alma iþlemi
  std::cout << "\nBaslangic Zamanini Girin (HH:MM): ";
  std::getline(std::cin, startTime); // Baþlangýç zamaný al
  step_counter++; // Baþlangýç zamaný alma iþlemi
  std::cout << "\nBitis Zamanini Girin (HH:MM): ";
  std::getline(std::cin, endTime); // Bitiþ zamaný al
  step_counter++; // Bitiþ zamaný alma iþlemi
  std::cout << "\nAktiviteyi Girin: ";
  std::getline(std::cin, activity); // Aktivite detayýný al
  step_counter++; // Aktivite detayý alma iþlemi
  sqlite3* db = openScheduleDatabase(); // Veritabanýna baðlan
  step_counter++; // Veritabaný baðlantýsý iþlemi

  if (!db) return; // Baðlantý baþarýsýzsa çýk

  std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed);
  std::string derivedKey = vectorToString(derivedKeyVec);
  std::vector<int> encryptedEventName = whiteBoxAesEncrypt(eventName, derivedKey);
  std::string encryptedEventNameStr = vectorToString(encryptedEventName);
  std::vector<int> encryptedStartTime = whiteBoxAesEncrypt(startTime, derivedKey);
  std::string encryptedStartTimeStr = vectorToString(encryptedStartTime);
  std::vector<int> encryptedEndTime = whiteBoxAesEncrypt(endTime, derivedKey);
  std::string encryptedEndTimeStr = vectorToString(encryptedEndTime);
  std::vector<int> encryptedActivity = whiteBoxAesEncrypt(activity, derivedKey);
  std::string encryptedActivityStr = vectorToString(encryptedActivity);
  step_counter++; // AES þifreleme iþlemi
  // Zaman çizelgesi ekleme sorgusu
  std::string sql = "INSERT INTO schedule (event_name, start_time, end_time, activity) VALUES (?, ?, ?, ?);";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    // Sorgu hazýrlanamadýysa hata mesajý yazdýr ve çýk
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  // Parametreleri baðla
  sqlite3_bind_text(stmt, 1, encryptedEventNameStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2, encryptedStartTimeStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 3, encryptedEndTimeStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 4, encryptedActivityStr.c_str(), -1, SQLITE_STATIC);
  step_counter++; // Parametre baðlama iþlemi

  if (sqlite3_step(stmt) != SQLITE_DONE) {
    // Sorgu çalýþtýrýlamadýysa hata mesajý yazdýr
    std::cerr << "\nZaman cizelgesi ekleme hatasi: " << sqlite3_errmsg(db) << std::endl;
  } else {
    clearConsole(); // Konsolu temizle
    step_counter++; // Konsolu temizleme iþlemi
    std::cout << "\nZaman cizelgesi basariyla eklendi.\n"; // Baþarý mesajý
  }

  secureErase(eventName);
  secureErase(startTime);
  secureErase(endTime);
  secureErase(activity);
  secureErase(derivedKey);
  secureErase(encryptedEventNameStr);
  secureErase(encryptedStartTimeStr);
  secureErase(encryptedEndTimeStr);
  secureErase(encryptedActivityStr);
  step_counter++; // Güvenli silme iþlemi
  sqlite3_finalize(stmt); // Belleði serbest býrak
  sqlite3_close(db); // Veritabaný baðlantýsýný kapat
  step_counter++; // Bellek serbest býrakma ve baðlantý kapatma iþlemi
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol akýþý adýmlarýný yazdýr
}

/*
* @brief Organize activities
* 
* @return void
*
*/
LOCAL_EVENT_PLANNER_API void organizeActivities() {
  clearConsole(); // Konsolu temizle
  step_counter++; // Konsolu temizleme iþlemi
  sqlite3* db = openScheduleDatabase(); // Veritabanýna baðlan
  step_counter++; // Veritabaný baðlantýsý iþlemi

  if (!db) return; // Baðlantý baþarýsýzsa çýk

  // Etkinlikleri görüntüleme sorgusu
  std::string sql = "SELECT id, event_name, start_time, end_time, activity FROM schedule;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    // Sorgu hazýrlanamadýysa hata mesajý yazdýr ve çýk
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  std::cout << "\nZaman Cizelgesi:\n"; // Baþlýk yazýsý

  // Sorgu sonuçlarýný döngüyle iþle
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0); // Etkinlik ID'si
    std::string storedEventName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)); // Etkinlik adý
    std::string storedStartTime = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)); // Baþlangýç zamaný
    std::string storedEndTime = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)); // Bitiþ zamaný
    std::string storedActivity = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)); // Aktivite detaylarý
    step_counter++; // Sorgu sonuçlarýný alma iþlemi
    std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed); // Oturum anahtarýný al
    std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar vektörünü stringe dönüþtür
    std::vector<int> storedEventNameVec = stringToVector(storedEventName);
    std::string decryptedEventName = whiteBoxAesDecrypt(storedEventNameVec, derivedKey);
    std::vector<int> storedStartTimeVec = stringToVector(storedStartTime);
    std::string decryptedStartTime = whiteBoxAesDecrypt(storedStartTimeVec, derivedKey);
    std::vector<int> storedEndTimeVec = stringToVector(storedEndTime);
    std::string decryptedEndTime = whiteBoxAesDecrypt(storedEndTimeVec, derivedKey);
    std::vector<int> storedActivityVec = stringToVector(storedActivity);
    std::string decryptedActivity = whiteBoxAesDecrypt(storedActivityVec, derivedKey);
    step_counter++; // AES þifre çözme iþlemi
    // Etkinlik detaylarýný ekrana yazdýr
    std::cout << "-------------------------\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Etkinlik Adi: " << decryptedEventName << "\n";
    std::cout << "Baslangic: " << decryptedStartTime << "\n";
    std::cout << "Bitis: " << decryptedEndTime << "\n";
    std::cout << "Aktivite: " << decryptedActivity << "\n";
    std::cout << "-------------------------\n"; // Bölüm sonu çizgisi
    secureErase(storedEventName);
    secureErase(storedStartTime);
    secureErase(storedEndTime);
    secureErase(storedActivity);
    secureErase(derivedKey);
    secureErase(decryptedEventName);
    secureErase(decryptedStartTime);
    secureErase(decryptedEndTime);
    secureErase(decryptedActivity);
    step_counter++; // Güvenli silme iþlemi
  }

  sqlite3_finalize(stmt); // Belleði serbest býrak
  sqlite3_close(db); // Veritabaný baðlantýsýný kapat
  step_counter++; // Baðlantý kapatma iþlemi
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol akýþý adýmlarýný yazdýr
}
