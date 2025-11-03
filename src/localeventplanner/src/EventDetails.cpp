/*
* @file EventDetails.cpp
*
* @brief Provides functions for managing event details
*/
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



/*
* @brief Unnecessary function
*
* @param value
*
* @return bool
*/

bool isPrimes(int value) {
  if (value < 2) return false;

  for (int i = 2; i <= std::sqrt(value); ++i) {
    if (value % i == 0) return false;
  }

  return true;
}

/*
* @brief Unnecessary function for testing
*
* @return void
*/
void afffasdssdw() {
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
    if (isPrimes(value)) {
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
* @brief Opens the event database
*
* @return sqlite3* Database connection
*/
sqlite3 *openEventDatabase() {
  afffasdssdw();
  sqlite3 *db; // Veritabaný baðlantýsý için deðiþken
  int exit = sqlite3_open("events.db", &db); // Veritabanýný aç
  step_counter++; // Veritabaný açma iþlemi

  if (exit) {
    // Baðlantý baþarýsýzsa hata mesajý
    std::cerr << "\nEtkinlik veritabani acilamadi: " << sqlite3_errmsg(db) << std::endl;
    return nullptr;
  } else {
    clearConsole(); // Konsolu temizle
    std::cout << "\nEtkinlik veritabani basariyla acildi.\n";
    // "events" tablosunu oluþtur (yoksa)
    const char *sqlCreateTable =
      "CREATE TABLE IF NOT EXISTS events ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
      "name TEXT NOT NULL, " // Etkinlik adý
      "date TEXT NOT NULL, " // Etkinlik tarihi
      "location TEXT NOT NULL, " // Etkinlik lokasyonu
      "description TEXT);"; // Etkinlik açýklamasý
    char *errorMessage;
    exit = sqlite3_exec(db, sqlCreateTable, nullptr, 0, &errorMessage);
    step_counter++; // Tablo oluþturma iþlemi

    if (exit != SQLITE_OK) {
      // Tablo oluþturma baþarýsýzsa hata mesajý
      std::cerr << "Events tablosu olusturulurken hata: " << errorMessage << std::endl;
      sqlite3_free(errorMessage);
    }
  }

  return db; // Veritabaný baðlantýsýný döndür
}


/*
* @brief Creates a new event
*
* @return void
*
*/
LOCAL_EVENT_PLANNER_API void createEvent() {
  int resulst = 0;
  int temsp = 1;
  int bs = 5;
  int cde = 18;

  for (int i = 1; i <= 10; ++i) {
    temsp *= i % 3 + 1;         // Mod ve çarpma iþlemi
    resulst += temsp % 7 - 2;    // Mod, toplama ve çýkarma iþlemi
    resulst ^= (i * 5) & 3;     // XOR ve AND iþlemi

    if (resulst % 4 == 0) {     // Þartlý bir dönüþüm
      resulst += temsp / 2;
    }

    bs = cde + bs;
    temsp += resulst % 9;        // Döngü deðiþkeni üzerinde ek bir iþlem
  }

  cde = cde + bs;
  clearConsole(); // Konsolu temizle
  step_counter++; // Konsolu temizleme iþlemi
  std::string eventName, eventDate, eventLocation, eventDescription; // Kullanýcýdan alýnacak bilgiler
  // Kullanýcýdan etkinlik bilgilerini al
  std::cin.ignore(); // Girdi tamponunu temizle
  std::cout << "\nEtkinlik Adini Girin: ";
  std::getline(std::cin, eventName); // Etkinlik adý
  step_counter++; // Etkinlik adý alma iþlemi
  std::cout << "\nEtkinlik Tarihini Girin (YYYY-MM-DD): ";
  std::getline(std::cin, eventDate); // Etkinlik tarihi
  step_counter++; // Etkinlik tarihi alma iþlemi
  std::cout << "\nEtkinlik Lokasyonunu Girin: ";
  std::getline(std::cin, eventLocation); // Etkinlik lokasyonu
  step_counter++; // Etkinlik lokasyonu alma iþlemi
  std::cout << "\nEtkinlik Aciklamasini Girin: ";
  std::getline(std::cin, eventDescription); // Etkinlik açýklamasý
  step_counter++; // Etkinlik açýklamasý alma iþlemi
  // Veritabanýna baðlan
  sqlite3 *db = openEventDatabase();

  if (!db) return; // Baðlantý baþarýsýzsa çýk

  std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed);
  std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar türet
  std::vector<int> encryptedEventName = whiteBoxAesEncrypt(eventName, derivedKey);
  std::string encryptedEventNameStr = vectorToString(encryptedEventName);
  std::vector<int> encryptedEventDate = whiteBoxAesEncrypt(eventDate, derivedKey);
  std::string encryptedEventDateStr = vectorToString(encryptedEventDate);
  std::vector<int> encryptedEventLocation = whiteBoxAesEncrypt(eventLocation, derivedKey);
  std::string encryptedEventLocationStr = vectorToString(encryptedEventLocation);
  std::vector<int> encryptedEventDescription = whiteBoxAesEncrypt(eventDescription, derivedKey);
  std::string encryptedEventDescriptionStr = vectorToString(encryptedEventDescription);
  step_counter++; // AES þifreleme iþlemi
  // SQL sorgusunu hazýrla ve parametreleri baðla
  std::string sql = "INSERT INTO events (name, date, location, description) VALUES (?, ?, ?, ?);";
  sqlite3_stmt *stmt;
  sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
  step_counter++; // Sorgu hazýrlama iþlemi
  sqlite3_bind_text(stmt, 1, encryptedEventNameStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2, encryptedEventDateStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 3, encryptedEventLocationStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 4, encryptedEventDescriptionStr.c_str(), -1, SQLITE_STATIC);
  step_counter++; // Parametreleri baðlama iþlemi

  // Sorguyu çalýþtýr ve durumu kontrol et
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    std::cerr << "\nEtkinlik ekleme hatasi: " << sqlite3_errmsg(db) << std::endl;
  } else {
    std::cout << "\nEtkinlik basariyla olusturuldu.\n"; // Baþarý mesajý
  }

  secureErase(eventName);
  secureErase(eventDate);
  secureErase(eventLocation);
  secureErase(eventDescription);
  secureErase(derivedKey);
  secureErase(encryptedEventNameStr);
  secureErase(encryptedEventDateStr);
  secureErase(encryptedEventLocationStr);
  secureErase(encryptedEventDescriptionStr);
  secureErase(encryptedEventNameStr);
  step_counter++; // Güvenli silme iþlemi
  sqlite3_finalize(stmt); // Belleði serbest býrak
  sqlite3_close(db); // Veritabaný baðlantýsýný kapat
  step_counter++; // Bellek serbest býrakma iþlemi
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol akýþý adýmlarýný yazdýr
}

/*
* @brief Manages events
*
* @return void
*/
LOCAL_EVENT_PLANNER_API void manageEvents() {
  sqlite3 *db = openEventDatabase(); // Veritabanýna baðlan
  step_counter++; // Veritabaný baðlantýsý

  if (!db) return; // Baðlantý baþarýsýzsa çýk

  // Etkinlikleri listelemek için SQL sorgusu
  std::string sql = "SELECT id, name, date, location, description FROM events;";
  sqlite3_stmt *stmt;

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    // Hata durumunda mesaj göster ve çýk
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  step_counter++; // Sorgu hazýrlama iþlemi
  // Etkinlik listesini ekrana yazdýr
  std::cout << "\nEtkinlik Listesi:\n";

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0); // Etkinlik ID'sini al
    std::string storedEventName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)); // Etkinlik adý
    std::string storedEventDate = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)); // Etkinlik tarihi
    std::string storedEventLocation = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)); // Etkinlik lokasyonu
    std::string storedEventDescription = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)); // Etkinlik açýklamasý
    step_counter++; // Etkinlik bilgilerini alma iþlemi
    std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed); // Oturum anahtarýný al
    std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar vektörünü stringe dönüþtür
    std::vector<int> storedEventNameVec = stringToVector(storedEventName);
    std::string decryptedEventName = whiteBoxAesDecrypt(storedEventNameVec, derivedKey);
    std::vector<int> storedEventDateVec = stringToVector(storedEventDate);
    std::string decryptedEventDate = whiteBoxAesDecrypt(storedEventDateVec, derivedKey);
    std::vector<int> storedEventLocationVec = stringToVector(storedEventLocation);
    std::string decryptedEventLocation = whiteBoxAesDecrypt(storedEventLocationVec, derivedKey);
    std::vector<int> storedEventDescriptionVec = stringToVector(storedEventDescription);
    std::string decryptedEventDescription = whiteBoxAesDecrypt(storedEventDescriptionVec, derivedKey);
    step_counter++; // AES þifre çözme iþlemi
    // Etkinlik bilgilerini yazdýr
    std::cout << "-------------------------\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Ad: " << decryptedEventName << "\n";
    std::cout << "Tarih: " << decryptedEventDate << "\n";
    std::cout << "Lokasyon: " << decryptedEventLocation << "\n";
    std::cout << "Aciklama: " << decryptedEventDescription << "\n";
    std::cout << "-------------------------\n";
    secureErase(derivedKey);
    secureErase(storedEventName);
    secureErase(storedEventDate);
    secureErase(storedEventLocation);
    secureErase(storedEventDescription);
    secureErase(decryptedEventName);
    secureErase(decryptedEventDate);
    secureErase(decryptedEventLocation);
    secureErase(decryptedEventDescription);
    step_counter++; // Güvenli silme iþlemi
  }

  sqlite3_finalize(stmt); // Belleði serbest býrak
  sqlite3_close(db); // Veritabaný baðlantýsýný kapat
  step_counter++; // Bellek serbest býrakma iþlemi
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol akýþý adýmlarýný yazdýr
}
