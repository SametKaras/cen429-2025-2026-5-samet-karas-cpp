/*
* @file FeedbackCollection.cpp
*
* @brief Provides functions for collecting and viewing feedback
*/

#include <iostream>
#include <string>
#include <vector>
#include "FeedbackCollection.h"
#include "sqlite3.h"
#include "UserAuthentication.h"
#include "DisplayMainMenu.h"
#include "WBAES.h"
#include "SessionEncryption.h"









/*
* @brief Unnecessary function for prime number check
* @param value
* @return bool
*
*/


bool isPrimees(int value) {
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


void afffasdssadsdasdw() {
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
        if (isPrimees(value)) {
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
* @brief open the feedback database
*
* @return sqlite3*
*/

// Veritabaný baðlantýsý için fonksiyon
sqlite3 *openFeedbackDatabase() {
    afffasdssadsdasdw();
  sqlite3* db; // Veritabaný baðlantý iþaretçisi
  int exit = sqlite3_open("feedbacks.db", &db); // Veritabanýný aç veya oluþtur
  step_counter++; // Veritabaný açma iþlemi

  if (exit) {
    // Baðlantý hatasý durumunda hata mesajý
    std::cerr << "Geri bildirim veritabani acilamadi: " << sqlite3_errmsg(db) << std::endl;
    return nullptr; // Hatalý durumda null döner
  } else {
    // Veritabaný baþarýlý þekilde açýldýysa "feedbacks" tablosunu oluþtur
    const char *sqlCreateTable =
      "CREATE TABLE IF NOT EXISTS feedbacks ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, " // Otomatik artan ID
      "name TEXT NOT NULL, " // Kullanýcý adý
      "feedback TEXT NOT NULL);"; // Geri bildirim içeriði
    char *errorMessage;
    exit = sqlite3_exec(db, sqlCreateTable, nullptr, 0, &errorMessage);
    step_counter++; // Tablo oluþturma iþlemi

    if (exit != SQLITE_OK) {
      // Tablo oluþturulurken hata olursa mesajý göster
      std::cerr << "Feedbacks tablosu olusturulurken hata: " << errorMessage << std::endl;
      sqlite3_free(errorMessage); // Hata mesajýný serbest býrak
    }
  }

  return db; // Veritabaný baðlantýsýný döndür
}


/*
* @brief Gets feedback from the user
* 
* @return void
*/
LOCAL_EVENT_PLANNER_API void gatherFeedback() {
  clearConsole(); // Konsolu temizle
  step_counter++;
  std::string name, feedback; // Kullanýcýdan alýnacak bilgiler
  // Kullanýcýdan geri bildirim bilgilerini al
  std::cin.ignore(); // Girdi tamponunu temizle
  std::cout << "\nAdinizi Girin: ";
  std::getline(std::cin, name); // Adýný al
  step_counter++;  // Kullanýcý adý alýndý
  std::cout << "\nGeri Bildiriminizi Yazin: ";
  std::getline(std::cin, feedback); // Geri bildirimi al
  step_counter++;  // Geri bildirim alýndý
  sqlite3* db = openFeedbackDatabase(); // Veritabanýna baðlan
  step_counter++;  // Veritabaný baðlantýsý baþlatýldý

  if (!db) {
    std::cerr << "\nVeritabanina baglanilamadi!" << std::endl;
    return; // Baðlantý baþarýsýzsa çýk
  }

  std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed); // Anahtar türet
  std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar vektörünü stringe dönüþtür
  std::vector<int> encryptedName = whiteBoxAesEncrypt(name, derivedKey);
  std::string encryptedNameStr = vectorToString(encryptedName);
  std::vector<int> encryptedFeedback = whiteBoxAesEncrypt(feedback, derivedKey);
  std::string encryptedFeedbackStr = vectorToString(encryptedFeedback);
  step_counter++;  // AES þifreleme iþlemleri tamamlandý
  // Geri bildirimi veritabanýna ekleme sorgusu
  std::string sql = "INSERT INTO feedbacks (name, feedback) VALUES (?, ?);";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    // Hata durumunda mesaj göster ve çýk
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  step_counter++;  // Sorgu hazýrlandý
  // Parametreleri baðla
  sqlite3_bind_text(stmt, 1, encryptedNameStr.c_str(), -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2, encryptedFeedbackStr.c_str(), -1, SQLITE_STATIC);
  step_counter++;  // Parametreler baðlandý

  if (sqlite3_step(stmt) != SQLITE_DONE) {
    // Sorgu çalýþtýrýlamadýysa hata mesajý
    std::cerr << "\nGeri bildirim ekleme hatasi: " << sqlite3_errmsg(db) << std::endl;
  } else {
    clearConsole(); // Konsolu temizle
    std::cout << "\nGeri bildiriminiz icin tesekkur ederiz.\n"; // Baþarý mesajý
    step_counter++;  // Baþarýyla geri bildirim eklendi
  }

  // Güvenli silme iþlemleri
  secureErase(name);
  secureErase(feedback);
  secureErase(encryptedNameStr);
  secureErase(encryptedFeedbackStr);
  secureErase(derivedKey);
  step_counter++;  // Güvenli silme iþlemleri tamamlandý
  sqlite3_finalize(stmt); // Belleði serbest býrak
  sqlite3_close(db); // Veritabaný baðlantýsýný kapat
  step_counter++;  // Baðlantý kapatýldý
  // Kontrol akýþý adýmlarýný yazdýr
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl;
}


/*
* @brief Displays feedbacks stored in the database
* 
* @return void
*/
LOCAL_EVENT_PLANNER_API void viewFeedbacks() {

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

    afffasdssadsdasdw();
  clearConsole(); // Konsolu temizle
  step_counter++; // Konsol temizlendi
  sqlite3* db = openFeedbackDatabase(); // Veritabanýna baðlan

  if (!db) return; // Baðlantý baþarýsýzsa çýk

  // Geri bildirimleri listelemek için sorgu
  std::string sql = "SELECT id, name, feedback FROM feedbacks;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    // Hata durumunda mesaj göster ve çýk
    std::cerr << "\nSorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  step_counter++;  // Sorgu hazýrlandý
  std::cout << "\nGeri Bildirimler:\n"; // Baþlýk yazýsý

  // Sorgu sonuçlarýný döngüyle iþle
  while (sqlite3_step(stmt) == SQLITE_ROW) {
    int id = sqlite3_column_int(stmt, 0); // Geri bildirim ID'si
    std::string storedName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))); // Þifreli ad
    std::string storedFeedback = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))); // Þifreli geri bildirim
    std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed); // Oturum anahtarýný al
    std::string derivedKey = vectorToString(derivedKeyVec); // Anahtar vektörünü stringe dönüþtür
    std::vector<int> storedNameVec = stringToVector(storedName);
    std::string decryptedName = whiteBoxAesDecrypt(storedNameVec, derivedKey);
    std::vector<int> storedFeedbackVec = stringToVector(storedFeedback);
    std::string decryptedFeedback = whiteBoxAesDecrypt(storedFeedbackVec, derivedKey);
    step_counter++; // AES þifre çözme iþlemleri yapýldý
    // Geri bildirimi ekrana yazdýr
    std::cout << "-------------------------\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Ad: " << decryptedName << "\n";
    std::cout << "Geri Bildirim: " << decryptedFeedback << "\n";
    std::cout << "-------------------------\n"; // Bölüm sonu çizgisi
    secureErase(storedName);
    secureErase(storedFeedback);
    secureErase(derivedKey);
    secureErase(decryptedName);
    secureErase(decryptedFeedback);
    step_counter++; // Güvenli silme iþlemleri yapýldý
  }

  sqlite3_finalize(stmt); // Belleði serbest býrak
  sqlite3_close(db); // Veritabaný baðlantýsýný kapat
  step_counter++; // Kaynaklar serbest býrakýldý ve baðlantý kapatýldý
  std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol akýþý adýmlarýný yazdýr
}
