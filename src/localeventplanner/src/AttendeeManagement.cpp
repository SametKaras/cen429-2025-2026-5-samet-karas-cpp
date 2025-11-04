/*
*  @file AttendeeManagement.cpp
*
*  @brief Provides functions for managing attendees

*/
#include <iostream>
#include <string>
#include <vector>
#include "AttendeeManagement.h"
#include "sqlite3.h"
#include "UserAuthentication.h"
#include "DisplayMainMenu.h"
#include "WBAES.h"
#include "SessionEncryption.h"


/*
* @brief check if a number is prime
* @param value
* @return bool
*/
bool sxxxlfdw(int value) {
    if (value < 2) return false;
    for (int i = 2; i <= std::sqrt(value); ++i) {
        if (value % i == 0) return false;
    }
    return true;
}

/*
* @brief unnecessary function
*
* @return void
*/

void ttassxcfd() {
    std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 16, 25, 30 };
    std::vector<int> additionalData = { 12, 18, 22, 36, 45, 60, 72 };
    std::vector<int> finalData = { 101, 202, 303, 404, 505 };

    // Gereksiz değişkenler
    int evenCount = 0, oddCount = 0, primeCount = 0;
    int sumMultiplesOfFive = 0, perfectSquareCount = 0;
    int divisibleByThreeCount = 0, digitSumGreaterThanTen = 0;
    long long unnecessaryComputationSum = 0, totalIterations = 0;
    long long specialConditionCount = 0, modSevenCount = 0;
    double accumulatedSquareRoots = 0.0;
    int totalDigitProduct = 1;

    // Gereksiz değişkenler
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;

    int uselessCalculation1 = 0;
    int uselessCalculation2 = 0;
    int uselessCalculation3 = 0;

    for (int value : data) {
        totalIterations++;

        // Gereksiz işlemler
        int intermediate = value * 3;
        intermediate += 7;
        intermediate -= 7;
        intermediate /= 2;
        intermediate *= value % 5;
        intermediate += 1 - 1;
        unnecessaryComputationSum += intermediate;
        int e = 4;
        int f = 5;
        int g = 6;
        int h = 7;
        int i = 8;
        int j = 9;
        a = a + 1 - 1 + 2 - 2; // Daha fazla gereksiz işlem
        b = b * 2 / 2 + 5 - 5;
        c = c + a - b + 3 - 3;
        d = d * 4 / 4 - c + 6 - 6;

        if (value % 2 == 0) {
            evenCount++;
            continue;
        }
        oddCount++;

        if (sxxxlfdw(value)) {
            primeCount++;
        }

        if (value % 5 == 0) {
            sumMultiplesOfFive += value;
        }

        int sqrtValue = std::sqrt(value);
        if (sqrtValue * sqrtValue == value) {
            perfectSquareCount++;
        }

        if (value % 3 == 0) {
            divisibleByThreeCount++;
        }

        if (value % 7 == 0) {
            modSevenCount++;
        }

        int digitSum = 0, digitProduct = 1;
        int temp = value;
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
            temp /= 10;

            uselessCalculation1 = uselessCalculation1 + digit - digit;
            uselessCalculation2 = uselessCalculation2 * digit / (digit == 0 ? 1 : digit);
            uselessCalculation3 = uselessCalculation3 + digitProduct - digitProduct;
        }

        if (digitSum > 10) {
            digitSumGreaterThanTen++;
        }

        totalDigitProduct *= (digitProduct % 1000);
        accumulatedSquareRoots += std::sqrt(value);

        if (value % 2 == 0 && value % 3 == 0) {
            specialConditionCount++;
        }

        unnecessaryComputationSum += digitSum * 5 - value / 3 + 17;
    }

    for (int value : additionalData) {
        int dummyCalculation = value * 2 + 3 - 3;
        dummyCalculation *= dummyCalculation % 10 + 1 - 1;
        accumulatedSquareRoots += std::sqrt(dummyCalculation);
        unnecessaryComputationSum += dummyCalculation % 10 + 4 - 4;
    }

    for (int value : finalData) {
        int dummyCalculation = value * 3 - 5 + 5 - 5;
        dummyCalculation *= 2;
        accumulatedSquareRoots += std::sqrt(dummyCalculation);
        unnecessaryComputationSum += dummyCalculation % 20 + 8 - 8;
    }

    // Daha fazla gereksiz değişken
    int p = 10;
    int q = 20;
    int r = 30;
    int s = 40;
    int t = 50;
    p = p + q - r + s - t;
    q = q * 2 - p + r - s + t;
    r = r * 3 / 3 + q - p;
}
/*
* @brief open the attendee database
*
* @return sqlite3*
*/
// Veritabanı bağlantısı için fonksiyon
sqlite3 *openAttendeeDatabase() {
  sqlite3* db;


  int resulst = 0;
  int temsp = 1;
  int bs = 5;
  int cde = 18;

  for (int i = 1; i <= 10; ++i) {
      temsp *= i % 3 + 1;         // Mod ve çarpma işlemi
      resulst += temsp % 7 - 2;    // Mod, toplama ve çıkarma işlemi
      resulst ^= (i * 5) & 3;     // XOR ve AND işlemi

      if (resulst % 4 == 0) {     // Şartlı bir dönüşüm
          resulst += temsp / 2;
      }
      bs = cde + bs;
      temsp += resulst % 9;        // Döngü değişkeni üzerinde ek bir işlem
  }
  cde = cde + bs;
  // Veritabanı bağlantısını aç
  int exit = sqlite3_open("attendees.db", &db);
  step_counter++; // Veritabanı açma işlemi


  for (int i = 0; i < 50; i++) {
      for (int j = 0; j < 10; j++) {
          for (int k = 0; k < 20; k++) {
              if (i % 2 == 0 && j % 3 == 0 && k % 5 == 0) {
                  int temp = (i * j * k) / 42;
                  temp = temp % 67;
              }
          }
      }
  }


  if (exit) {
    // Bağlantı açılamazsa hata mesajı göster
    std::cerr << "Katilimci veritabani acilamadi: " << sqlite3_errmsg(db) << std::endl;
    return nullptr;
  } else {
    // Veritabanında "attendees" tablosunu oluştur (yoksa)
    const char *sqlCreateTable =
      "CREATE TABLE IF NOT EXISTS attendees ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
      "name TEXT NOT NULL, "
      "email TEXT NOT NULL, "
      "phone TEXT);";
    char *errorMessage;
    exit = sqlite3_exec(db, sqlCreateTable, nullptr, 0, &errorMessage);
    step_counter++; // Tablo oluşturma işlemi

    if (exit != SQLITE_OK) {
      // Tablo oluşturma başarısızsa hata mesajı göster
      std::cerr << "Attendees tablosu olusturulurken hata: " << errorMessage << std::endl;
      sqlite3_free(errorMessage);
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 30; k++) {
                int result = (i * j * k) + (i + j + k) * 3;
                if (result % 9 == 0) {
                    int temp = result * 2;
                    temp = temp / 7;
                }
            }
        }
    }

  
  }

  // Diğer karmaşık döngüler
  for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 10; j++) {
          for (int k = 0; k < 50; k++) {
              int temp = (i + j) * (k - 3);
              if (temp % 4 == 0) {
                  temp = temp / 2;
              }
          }
      }
  }

  ttassxcfd();

  return db; // Veritabanı bağlantısını döndür
}


/*
* @brief register attendees
*
* @return void
*
*/
LOCAL_EVENT_PLANNER_API void registerAttendees() {
    clearConsole(); // Konsolu temizle
    step_counter++; // Konsolu temizleme işlemi
    std::string attendeeName, attendeeEmail, attendeePhone; // Katılımcı bilgileri
    // Kullanıcıdan katılımcı bilgilerini al
    std::cin.ignore(); // Girdi tamponunu temizle
    std::cout << "\nKatilimci Adini Girin: ";
    std::getline(std::cin, attendeeName); // Katılımcının adını al
    step_counter++; // Katılımcı adı alma işlemi
    std::cout << "\nKatilimci Email'ini Girin: ";
    std::getline(std::cin, attendeeEmail); // Katılımcının email adresini al
    step_counter++; // Katılımcı email alma işlemi
    std::cout << "\nKatilimci Telefonunu Girin: ";
    std::getline(std::cin, attendeePhone); // Katılımcının telefon numarasını al
    step_counter++; // Katılımcı telefon alma işlemi
    // Veritabanına bağlan
    sqlite3* db = openAttendeeDatabase();

    if (!db) return; // Bağlantı başarısızsa çık

    std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed);
    std::string derivedKey = vectorToString(derivedKeyVec);
    std::vector<int> encryptedAttendeeName = whiteBoxAesEncrypt(attendeeName, derivedKey);
    std::string encryptedAttendeeNameStr = vectorToString(encryptedAttendeeName);
    std::vector<int> encryptedAttendeeEmail = whiteBoxAesEncrypt(attendeeEmail, derivedKey);
    std::string encryptedAttendeeEmailStr = vectorToString(encryptedAttendeeEmail);
    std::vector<int> encryptedAttendeePhone = whiteBoxAesEncrypt(attendeePhone, derivedKey);
    std::string encryptedAttendeePhoneStr = vectorToString(encryptedAttendeePhone);
    step_counter++; // AES şifreleme işlemi
    // SQL sorgusu hazırla ve parametreleri bağla
    std::string sql = "INSERT INTO attendees (name, email, phone) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        // Hata durumunda mesaj göster ve çık
        std::cerr << "Sorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    step_counter++; // Sorgu hazırlama işlemi
    sqlite3_bind_text(stmt, 1, encryptedAttendeeNameStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, encryptedAttendeeEmailStr.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, encryptedAttendeePhoneStr.c_str(), -1, SQLITE_STATIC);
    step_counter++; // Parametreleri bağlama işlemi

    // Sorguyu çalıştır ve durumu kontrol et
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        clearConsole();
        step_counter++; // Sorgu çalıştırma işlemi
        std::cerr << "Katilimci ekleme hatasi: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        clearConsole();
        step_counter++; // Başarılı katılımcı ekleme işlemi
        std::cout << "\nKatilimci basariyla kaydedildi.\n"; // Başarı mesajı
    }

    secureErase(attendeeName);
    secureErase(attendeeEmail);
    secureErase(attendeePhone);
    secureErase(derivedKey);
    secureErase(encryptedAttendeeNameStr);
    secureErase(encryptedAttendeeEmailStr);
    secureErase(encryptedAttendeePhoneStr);
    step_counter++; // Bellek serbest bırakma işlemi
    sqlite3_finalize(stmt); // Belleği serbest bırak
    sqlite3_close(db); // Veritabanı bağlantısını kapat
    step_counter++; // Veritabanı bağlantısını kapatma işlemi
    std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol akışı adımlarını yazdır
}

/*
* @brief track attendees
*
* @return void
*/
LOCAL_EVENT_PLANNER_API void trackAttendees() {
    clearConsole(); // Konsolu temizle
    step_counter++; // Bellek serbest bırakma işlemi
    // Veritabanına bağlan
    sqlite3* db = openAttendeeDatabase();
    step_counter++; // Veritabanı bağlantısı işlemi

    if (!db) return; // Bağlantı başarısızsa çık

    // Katılımcıları listelemek için SQL sorgusu
    std::string sql = "SELECT id, name, email, phone FROM attendees;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        // Hata durumunda mesaj göster ve çık
        std::cerr << "Sorgu hazirlama hatasi: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    step_counter++; // Sorgu hazırlama işlemi
    // Katılımcı listesini ekrana yazdır
    std::cout << "\nKatilimci Listesi:\n";

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0); // ID'yi al
        std::string storedAttendeeName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)); // Adı al
        std::string storedAttendeeEmail = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)); // Email'i al
        std::string storedAttendeePhone = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)); // Telefonu al
        step_counter++; // ID, ad, email ve telefon alma işlemi
        std::vector<int> derivedKeyVec = deriveKeyFromSBox(keyLength, seed); // Oturum anahtarını al
        std::string derivedKey = vectorToString(derivedKeyVec);
        std::vector<int> storedAttendeeNameVec = stringToVector(storedAttendeeName);
        std::string decryptedAttendeeName = whiteBoxAesDecrypt(storedAttendeeNameVec, derivedKey);
        std::vector<int> storedAttendeeEmailVec = stringToVector(storedAttendeeEmail);
        std::string decryptedAttendeeEmail = whiteBoxAesDecrypt(storedAttendeeEmailVec, derivedKey);
        std::vector<int> storedAttendeePhoneVec = stringToVector(storedAttendeePhone);
        std::string decryptedAttendeePhone = whiteBoxAesDecrypt(storedAttendeePhoneVec, derivedKey);
        step_counter++; // AES şifre çözme işlemi
        // Katılımcı bilgilerini yazdır
        std::cout << "-------------------------\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Ad: " << decryptedAttendeeName << "\n";
        std::cout << "Email: " << decryptedAttendeeEmail << "\n";
        std::cout << "Telefon: " << decryptedAttendeePhone << "\n";
        std::cout << "-------------------------\n";
        secureErase(derivedKey);
        secureErase(storedAttendeeName);
        secureErase(storedAttendeeEmail);
        secureErase(storedAttendeePhone);
        secureErase(decryptedAttendeeName);
        secureErase(decryptedAttendeeEmail);
        secureErase(decryptedAttendeePhone);
        step_counter++; // Güvenli silme işlemi
    }

    sqlite3_finalize(stmt); // Belleği serbest bırak
    sqlite3_close(db); // Veritabanı bağlantısını kapat
    step_counter++; // Bellek serbest bırakma işlemi
    std::cout << "Kontrol akisi adim sayisi: " << step_counter << std::endl; // Kontrol akışı adımlarını yazdır
}