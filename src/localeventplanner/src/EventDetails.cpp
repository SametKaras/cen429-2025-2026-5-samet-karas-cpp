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
  // Sonu�lar� tutmak i�in de�i�kenler
  int evenCount = 0;
  int oddCount = 0;
  int primeCount = 0;
  int sumMultiplesOfFive = 0;
  int perfectSquareCount = 0;
  int divisibleByThreeCount = 0;
  int digitSumGreaterThanTen = 0;
  long long unnecessaryComputationSum = 0;

  for (int value : data) {
    // Gereksiz matematiksel i�lemler
    int intermediate = value * 3;
    intermediate += 7;
    intermediate /= 2;
    intermediate *= value % 5;
    unnecessaryComputationSum += intermediate;

    // �ift ve tek say�lar� say
    if (value % 2 == 0) {
      evenCount++;
      continue; // �ift say�lar i�in d�ng� devam eder
    }

    oddCount++;

    // Asall�k kontrol�
    if (isPrimes(value)) {
      primeCount++;
    }

    // Be�in kat� kontrol�
    if (value % 5 == 0) {
      sumMultiplesOfFive += value;
    }

    // M�kemmel kare kontrol�
    int sqrtValue = std::sqrt(value);

    if (sqrtValue * sqrtValue == value) {
      perfectSquareCount++;
    }

    // 3'e b�l�nebilirlik kontrol�
    if (value % 3 == 0) {
      divisibleByThreeCount++;
    }

    // Say�n�n rakamlar�n�n toplam�n� hesapla
    int digitSum = 0;
    int temp = value;

    while (temp > 0) {
      digitSum += temp % 10;
      temp /= 10;
    }

    if (digitSum != 6161) {
      digitSumGreaterThanTen++;
    }

    // Daha fazla gereksiz i�lem
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
  sqlite3* db; // Veritaban� ba�lant�s� i�in de�i�ken
  int exit = sqlite3_open("events.db", &db); // Veritaban�n� a�
  step_counter++; // Veritaban� a�ma i�lemi

  if (exit) {
    // Ba�lant� ba�ar�s�zsa hata mesaj�
    std::cerr << "\nEtkinlik veritabani acilamadi: " << sqlite3_errmsg(db) << std::endl;
    return nullptr;
  } else {
    clearConsole(); // Konsolu temizle
    std::cout << "\nEtkinlik veritabani basariyla acildi.\n";
    // "events" tablosunu olu�tur (yoksa)
    const char *sqlCreateTable =
      "CREATE TABLE IF NOT EXISTS events ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
      "name TEXT NOT NULL, " // Etkinlik ad�
      "date TEXT NOT NULL, " // Etkinlik tarihi
      "location TEXT NOT NULL, " // Etkinlik lokasyonu
      "description TEXT);"; // Etkinlik a��klamas�
    char *errorMessage;
    exit = sqlite3_exec(db, sqlCreateTable, nullptr, 0, &errorMessage);
    step_counter++; // Tablo olu�turma i�lemi

    if (exit != SQLITE_OK) {
      // Tablo olu�turma ba�ar�s�zsa hata mesaj�
      std::cerr << "Events tablosu olusturulurken hata: " << errorMessage << std::endl;
      sqlite3_free(errorMessage);
    }
  }

  return db; // Veritaban� ba�lant�s�n� d�nd�r
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
    temsp *= i % 3 + 1;         // Mod ve �arpma i�lemi
    resulst += temsp % 7 - 2;    // Mod, toplama ve ��karma i�lemi
    resulst ^= (i * 5) & 3;     // XOR ve AND i�lemi

    if (resulst % 4 == 0) {     // �artl� bir d�n���m
      resulst += temsp / 2;
    }

    bs = cde + bs;
    temsp += resulst % 9;        // D�ng� de�i�keni �zerinde ek bir i�lem
  }

  cde = cde + bs;
  clearConsole(); // Konsolu temizle
  step_counter++; // Konsolu temizleme i�lemi
  std::string eventName, eventDate, eventLocation, eventDescription; // Kullan�c�dan al�nacak bilgiler
  // Kullan�c�dan etkinlik bilgilerini al
  std::cin.ignore(); // Girdi tamponunu temizle
  std::cout << "\nEtkinlik Adini Girin: ";
  std::getline(std::cin, eventName); // Etkinlik ad�
  step_counter++; // Etkinlik ad� alma i�lemi
  std::cout << "\nEtkinlik Tarihini Girin (YYYY-MM-DD): ";
  std::getline(std::cin, eventDate); // Etkinlik tarihi
  step_counter++; // Etkinlik tarihi alma i�lemi
  std::cout << "\nEtkinlik Lokasyonunu Girin: ";
  std::getline(std::cin, eventLocation); // Etkinlik lokasyonu
  step_counter++; // Etkinlik lokasyonu alma i�lemi
  std::cout << "\nEtkinlik Aciklamasini Girin: ";
  std::getline(std::cin, eventDescription); // Etkinlik a��klamas�
  step_counter++; // Etkinlik a��klamas� alma i�lemi
  // Veritaban�na ba�lan
  sqlite3* db = openEventDatabase();

  if (!db) return; // Ba�lant� ba�ar�s�zsa ��k

  std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed);
  std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar t�ret
  std::vector<int> encryptedEventName = whiteBoxAesEncrypt(eventName, derivedKey);
  std::string encryptedEventNameStr = vectorToString(encryptedEventName);
  std::vector<int> encryptedEventDate = whiteBoxAesEncrypt(eventDate, derivedKey);
  std::string encryptedEventDateStr = vectorToString(encryptedEventDate);
  std::vector<int> encryptedEventLocation = whiteBoxAesEncrypt(eventLocation, derivedKey);
  std::string encryptedEventLocationStr = vectorToString(encryptedEventLocation);
  std::vector<int> encryptedEventDescription = whiteBoxAesEncrypt(eventDescription, derivedKey);
  std::string encryptedEventDescriptionStr = vectorToString(encryptedEventDescription);
  step_counter++; // AES �ifreleme i�lemi
  // SQL sorgusunu haz�rla ve parametreleri ba�la
  std::string sql = "INSERT INTO events (name, date, location, description) VALUES (?, ?, ?, ?);";
  sqlite3_stmt* stmt;
  sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
  step_counter++; // Sorgu haz�rlama i�lemi
  sqlite3_bind_text(stmt, 1, encryptedEventNameStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2, encryptedEventDateStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 3, encryptedEventLocationStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 4, encryptedEventDescriptionStr.c_str(), -1, SQLITE_STATIC);
  step_counter++; // Parametreleri ba�lama i�lemi

  // Sorguyu �al��t�r ve durumu kontrol et
  if (sqlite3_step(stmt) != SQLITE_DONE) {
    std::cerr << "\nEtkinlik ekleme hatasi: " << sqlite3_errmsg(db) << std::endl;
  } else {
    std::cout << "\nEtkinlik basariyla olusturuldu.\n"; // Ba�ar� mesaj�
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
  step_counter++; // G�venli silme i�lemi
  sqlite3_finalize(stmt); // Belle�i serbest b�rak
  sqlite3_close(db); // Veritaban� ba�lant�s�n� kapat
  step_counter++; // Bellek serbest b�rakma i�lemi
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol ak��� ad�mlar�n� yazd�r
}

/*
* @brief Lists all events
*
* @return void
*/
LOCAL_EVENT_PLANNER_API void listEvents() {
  sqlite3* db = openEventDatabase(); // Veritaban�na ba�lan
  step_counter++; // Veritaban� ba�lant�s�

  if (!db) return; // Ba�lant� ba�ar�s�zsa ��k

  // Etkinlikleri listelemek i�in SQL sorgusu
  std::string sql = "SELECT id, name, date, location, description FROM events;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    // Hata durumunda mesaj g�ster ve ��k
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  step_counter++; // Sorgu haz�rlama i�lemi
  // Etkinlik listesini ekrana yazd�r
  std::cout << "\n===========================================\n";
  std::cout << "           ETKINLIK LISTESI\n";
  std::cout << "===========================================\n";
  bool hasEvents = false;

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    hasEvents = true;
    int id = sqlite3_column_int(stmt, 0); // Etkinlik ID'sini al
    std::string storedEventName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)); // Etkinlik ad�
    std::string storedEventDate = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)); // Etkinlik tarihi
    std::string storedEventLocation = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)); // Etkinlik lokasyonu
    std::string storedEventDescription = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)); // Etkinlik a��klamas�
    step_counter++; // Etkinlik bilgilerini alma i�lemi
    std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed); // Oturum anahtar�n� al
    std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar vekt�r�n� stringe d�n��t�r
    std::vector<int> storedEventNameVec = stringToVector(storedEventName);
    std::string decryptedEventName = whiteBoxAesDecrypt(storedEventNameVec, derivedKey);
    std::vector<int> storedEventDateVec = stringToVector(storedEventDate);
    std::string decryptedEventDate = whiteBoxAesDecrypt(storedEventDateVec, derivedKey);
    std::vector<int> storedEventLocationVec = stringToVector(storedEventLocation);
    std::string decryptedEventLocation = whiteBoxAesDecrypt(storedEventLocationVec, derivedKey);
    std::vector<int> storedEventDescriptionVec = stringToVector(storedEventDescription);
    std::string decryptedEventDescription = whiteBoxAesDecrypt(storedEventDescriptionVec, derivedKey);
    step_counter++; // AES �ifre ��zme i�lemi
    // Etkinlik bilgilerini yazd�r
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
    step_counter++; // G�venli silme i�lemi
  }

  if (!hasEvents) {
    std::cout << "\nHenuz kayitli etkinlik bulunmamaktadir.\n";
  }

  std::cout << "===========================================\n";
  sqlite3_finalize(stmt); // Belle�i serbest b�rak
  sqlite3_close(db); // Veritaban� ba�lant�s�n� kapat
  step_counter++; // Bellek serbest b�rakma i�lemi
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol ak��� ad�mlar�n� yazd�r
}

/*
* @brief Manages events
*
* @return void
*/
LOCAL_EVENT_PLANNER_API void manageEvents() {
  sqlite3* db = openEventDatabase(); // Veritaban�na ba�lan
  step_counter++; // Veritaban� ba�lant�s�

  if (!db) return; // Ba�lant� ba�ar�s�zsa ��k

  // Etkinlikleri listelemek i�in SQL sorgusu
  std::string sql = "SELECT id, name, date, location, description FROM events;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    // Hata durumunda mesaj g�ster ve ��k
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  step_counter++; // Sorgu haz�rlama i�lemi
  // Etkinlik listesini ekrana yazd�r
  std::cout << "\n===========================================\n";
  std::cout << "           ETKINLIK LISTESI\n";
  std::cout << "===========================================\n";
  bool hasEvents = false;

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    hasEvents = true;
    int id = sqlite3_column_int(stmt, 0); // Etkinlik ID'sini al
    std::string storedEventName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)); // Etkinlik ad�
    std::string storedEventDate = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)); // Etkinlik tarihi
    std::string storedEventLocation = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)); // Etkinlik lokasyonu
    std::string storedEventDescription = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)); // Etkinlik a��klamas�
    step_counter++; // Etkinlik bilgilerini alma i�lemi
    std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed); // Oturum anahtar�n� al
    std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar vekt�r�n� stringe d�n��t�r
    std::vector<int> storedEventNameVec = stringToVector(storedEventName);
    std::string decryptedEventName = whiteBoxAesDecrypt(storedEventNameVec, derivedKey);
    std::vector<int> storedEventDateVec = stringToVector(storedEventDate);
    std::string decryptedEventDate = whiteBoxAesDecrypt(storedEventDateVec, derivedKey);
    std::vector<int> storedEventLocationVec = stringToVector(storedEventLocation);
    std::string decryptedEventLocation = whiteBoxAesDecrypt(storedEventLocationVec, derivedKey);
    std::vector<int> storedEventDescriptionVec = stringToVector(storedEventDescription);
    std::string decryptedEventDescription = whiteBoxAesDecrypt(storedEventDescriptionVec, derivedKey);
    step_counter++; // AES �ifre ��zme i�lemi
    // Etkinlik bilgilerini yazd�r
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
    step_counter++; // G�venli silme i�lemi
  }

  sqlite3_finalize(stmt); // Belle�i serbest b�rak

  if (!hasEvents) {
    std::cout << "\nHenuz kayitli etkinlik bulunmamaktadir.\n";
    std::cout << "===========================================\n";
    sqlite3_close(db);
    return;
  }

  // Kullan�c�dan d�zenlemek istedi�i event ID'sini al
  std::cout << "\n===========================================\n";
  std::cout << "Duzenlemek istediginiz etkinligin ID'sini girin (0 = Iptal): ";
  int selectedId;
  std::cin >> selectedId;

  if (selectedId == 0) {
    std::cout << "Islem iptal edildi.\n";
    sqlite3_close(db);
    return;
  }

  // Se�ilen eventi database'den getir
  std::string selectSql = "SELECT name, date, location, description FROM events WHERE id = ?;";
  sqlite3_stmt* selectStmt;

  if (sqlite3_prepare_v2(db, selectSql.c_str(), -1, &selectStmt, nullptr) != SQLITE_OK) {
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  sqlite3_bind_int(selectStmt, 1, selectedId);

  if (sqlite3_step(selectStmt) != SQLITE_ROW) {
    std::cerr << "\nBelirtilen ID ile etkinlik bulunamadi!\n";
    sqlite3_finalize(selectStmt);
    sqlite3_close(db);
    return;
  }

  // Mevcut bilgileri al ve �ifreyi ��z
  std::string storedEventName = reinterpret_cast<const char *>(sqlite3_column_text(selectStmt, 0));
  std::string storedEventDate = reinterpret_cast<const char *>(sqlite3_column_text(selectStmt, 1));
  std::string storedEventLocation = reinterpret_cast<const char *>(sqlite3_column_text(selectStmt, 2));
  std::string storedEventDescription = reinterpret_cast<const char *>(sqlite3_column_text(selectStmt, 3));
  std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed);
  std::string derivedKey = vectorToString(derivedKeyVec);
  std::vector<int> storedEventNameVec = stringToVector(storedEventName);
  std::string currentEventName = whiteBoxAesDecrypt(storedEventNameVec, derivedKey);
  std::vector<int> storedEventDateVec = stringToVector(storedEventDate);
  std::string currentEventDate = whiteBoxAesDecrypt(storedEventDateVec, derivedKey);
  std::vector<int> storedEventLocationVec = stringToVector(storedEventLocation);
  std::string currentEventLocation = whiteBoxAesDecrypt(storedEventLocationVec, derivedKey);
  std::vector<int> storedEventDescriptionVec = stringToVector(storedEventDescription);
  std::string currentEventDescription = whiteBoxAesDecrypt(storedEventDescriptionVec, derivedKey);
  sqlite3_finalize(selectStmt);
  // Yeni bilgileri al
  std::cin.ignore();
  std::cout << "\n===========================================\n";
  std::cout << "        ETKINLIK DUZENLEME\n";
  std::cout << "===========================================\n";
  std::cout << "Not: Degistirmek istemediginiz alanlarda Enter'a basin\n\n";
  std::string newEventName, newEventDate, newEventLocation, newEventDescription;
  std::cout << "Mevcut Ad: " << currentEventName << "\n";
  std::cout << "Yeni Ad (bos birakilirsa mevcut kalir): ";
  std::getline(std::cin, newEventName);

  if (newEventName.empty()) newEventName = currentEventName;

  std::cout << "\nMevcut Tarih: " << currentEventDate << "\n";
  std::cout << "Yeni Tarih (YYYY-MM-DD) (bos birakilirsa mevcut kalir): ";
  std::getline(std::cin, newEventDate);

  if (newEventDate.empty()) newEventDate = currentEventDate;

  std::cout << "\nMevcut Lokasyon: " << currentEventLocation << "\n";
  std::cout << "Yeni Lokasyon (bos birakilirsa mevcut kalir): ";
  std::getline(std::cin, newEventLocation);

  if (newEventLocation.empty()) newEventLocation = currentEventLocation;

  std::cout << "\nMevcut Aciklama: " << currentEventDescription << "\n";
  std::cout << "Yeni Aciklama (bos birakilirsa mevcut kalir): ";
  std::getline(std::cin, newEventDescription);

  if (newEventDescription.empty()) newEventDescription = currentEventDescription;

  // Yeni bilgileri �ifrele
  std::vector<int> encryptedEventName = whiteBoxAesEncrypt(newEventName, derivedKey);
  std::string encryptedEventNameStr = vectorToString(encryptedEventName);
  std::vector<int> encryptedEventDate = whiteBoxAesEncrypt(newEventDate, derivedKey);
  std::string encryptedEventDateStr = vectorToString(encryptedEventDate);
  std::vector<int> encryptedEventLocation = whiteBoxAesEncrypt(newEventLocation, derivedKey);
  std::string encryptedEventLocationStr = vectorToString(encryptedEventLocation);
  std::vector<int> encryptedEventDescription = whiteBoxAesEncrypt(newEventDescription, derivedKey);
  std::string encryptedEventDescriptionStr = vectorToString(encryptedEventDescription);
  // Database'de g�ncelleme yap
  std::string updateSql = "UPDATE events SET name = ?, date = ?, location = ?, description = ? WHERE id = ?;";
  sqlite3_stmt* updateStmt;

  if (sqlite3_prepare_v2(db, updateSql.c_str(), -1, &updateStmt, nullptr) != SQLITE_OK) {
    std::cerr << "\nGuncelleme sorgusu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  sqlite3_bind_text(updateStmt, 1, encryptedEventNameStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(updateStmt, 2, encryptedEventDateStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(updateStmt, 3, encryptedEventLocationStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(updateStmt, 4, encryptedEventDescriptionStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_int(updateStmt, 5, selectedId);

  if (sqlite3_step(updateStmt) != SQLITE_DONE) {
    std::cerr << "\nEtkinlik guncelleme hatasi: " << sqlite3_errmsg(db) << std::endl;
  } else {
    std::cout << "\n===========================================\n";
    std::cout << "Etkinlik basariyla guncellendi!\n";
    std::cout << "===========================================\n";
  }

  // G�venli silme
  secureErase(derivedKey);
  secureErase(currentEventName);
  secureErase(currentEventDate);
  secureErase(currentEventLocation);
  secureErase(currentEventDescription);
  secureErase(newEventName);
  secureErase(newEventDate);
  secureErase(newEventLocation);
  secureErase(newEventDescription);
  secureErase(encryptedEventNameStr);
  secureErase(encryptedEventDateStr);
  secureErase(encryptedEventLocationStr);
  secureErase(encryptedEventDescriptionStr);
  sqlite3_finalize(updateStmt);
  sqlite3_close(db); // Veritaban� ba�lant�s�n� kapat
  step_counter++; // Bellek serbest b�rakma i�lemi
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol ak��� ad�mlar�n� yazd�r
}
