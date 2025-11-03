#define ENABLE_LOCALEVENTPLANNER_TEST  // Uncomment this line to enable the LocalEventPlanner tests

#include "gtest/gtest.h"
#include "../../localeventplanner/header/UserAuthentication.h"
#include "../../localeventplanner/header/EventDetails.h"
#include "../../localeventplanner/header/WBAES.h"
#include "../../localeventplanner/header/SessionEncryption.h"
#include "../../localeventplanner/header/SaltAndHMAC.h"
#include "../../localeventplanner/header/DynamicAssetProtection.h"
#include "../../localeventplanner/header/DisplayMainMenu.h"
#include "sqlite3.h"
#include <iostream>
#include <string>
#include <vector>

// Veritabanı açma fonksiyonunun testi
TEST(UserAuthenticationTest, OpenUserDatabaseTest) {
  sqlite3 *db = openUserDatabase(); // Veritabanını aç
  ASSERT_NE(db, nullptr) << "Veritabanı açılamadı."; // Veritabanı bağlantısı boş olmamalı
  sqlite3_close(db);
}

TEST(EventDetailsTest, OpenEventDatabaseTest) {
  sqlite3 *db = openEventDatabase(); // Veritabanını aç
  ASSERT_NE(db, nullptr) << "Veritabanı açılamadı."; // Veritabanı bağlantısı boş olmamalı
  sqlite3_close(db);
}

// S-Box tablosu oluşturma testi
TEST(WBAESTest, CreateWhiteBoxTable) {
  std::vector<int> table = createWhiteBoxTable();
  ASSERT_EQ(table.size(), 256);

  // S-Box'tan doğru değerlerin kopyalandığını kontrol et
  for (int i = 0; i < 256; ++i) {
    ASSERT_EQ(table[i], S_BOX[i % S_BOX.size()]);
  }
}

// Anahtar türetme testi
TEST(WBAESTest, DeriveKeyFromSBox) {
  size_t keyLength = 4;
  unsigned char seedVal = 0x42;
  std::vector<int> key = deriveKeyFromSBox(keyLength, seedVal);
  ASSERT_EQ(key.size(), keyLength);

  // S-Box'tan doğru değerlerin türetildiğini kontrol et
  for (size_t i = 0; i < keyLength; ++i) {
    ASSERT_EQ(key[i], S_BOX[(seedVal + i) % 256]);
  }
}

// Şifreleme testi
TEST(WBAESTest, WhiteBoxAesEncrypt) {
  std::string plaintext = "test";
  std::string key = "anahtar";
  std::vector<int> encrypted = whiteBoxAesEncrypt(plaintext, key);
  ASSERT_EQ(encrypted.size(), plaintext.size());
}

// Şifre çözme testi
TEST(WBAESTest, WhiteBoxAesDecryptSuccess) {
  std::string plaintext = "test";
  std::string key = "key";
  std::vector<int> encrypted = whiteBoxAesEncrypt(plaintext, key);
  std::string decrypted;

  try {
    decrypted = whiteBoxAesDecrypt(encrypted, key);
  } catch (const std::runtime_error &e) {
    FAIL() << "Beklenmeyen bir istisna fırlatıldı: " << e.what();
  }

  ASSERT_EQ(decrypted, plaintext);
}

// Vector to String dönüşüm testi
TEST(WBAESTest, VectorToString) {
  std::vector<int> vec = { 97, 98, 99 }; // a, b, c
  std::string str = vectorToString(vec);
  ASSERT_EQ(str, "abc");
}

// String to Vector dönüşüm testi
TEST(WBAESTest, StringToVector) {
  std::string str = "abc";
  std::vector<int> vec = stringToVector(str);
  ASSERT_EQ(vec.size(), 3);
  ASSERT_EQ(vec[0], 97);
  ASSERT_EQ(vec[1], 98);
  ASSERT_EQ(vec[2], 99);
}

// Oturum şifreleme kurulumu testi
TEST(SessionEncryptionTest, SetupSessionEncryptionTest) {
  bool result = setupSessionEncryption();
  ASSERT_TRUE(result) << "Oturum şifreleme ayarları yapılamadı.";
}

// Şifre gücü testi
TEST(PasswordStrengthTest, ValidPasswords) {
  EXPECT_TRUE(isPasswordStrong("Str0ng!Pass")); // Güçlü şifre
  EXPECT_TRUE(isPasswordStrong("An0ther$Pass1")); // Güçlü şifre
}

TEST(PasswordStrengthTest, InvalidPasswords) {
  EXPECT_FALSE(isPasswordStrong("weak")); // Zayıf şifre
  EXPECT_FALSE(isPasswordStrong("NoNumber!")); // Rakam yok
  EXPECT_FALSE(isPasswordStrong("noupperca5e!")); // Büyük harf yok
}

// Salt oluşturma testi
TEST(UserAuthenticationTest, SaltGenerationTest) {
  std::string salt = generateFixedSalt("testSeed");
  ASSERT_FALSE(salt.empty()) << "Salt oluşturulamadı.";
}

// Cihaz parmak izi testi
TEST(UserAuthenticationTest, DeviceFingerprintTest) {
  std::string fingerprint = getEncryptedDeviceFingerprint();
  ASSERT_FALSE(fingerprint.empty()) << "Cihaz parmak izi oluşturulamadı.";
}

// Guest mode testleri
TEST(GuestModeTest, GetGuestModeTest) {
  setGuestMode(true);
  ASSERT_TRUE(getGuestMode());
  setGuestMode(false);
  ASSERT_FALSE(getGuestMode());
}

TEST(GuestModeTest, SetGuestModeTest) {
  setGuestMode(false);
  ASSERT_FALSE(getGuestMode());
  setGuestMode(true);
  ASSERT_TRUE(getGuestMode());
}

// Base64 kodlama/çözme testi
TEST(SessionEncryptionTest, Base64EncodingDecodingTest) {
  std::string testData = "Base64 Test Verisi";
  std::string encodedData = base64Encode(reinterpret_cast<const unsigned char *>(testData.c_str()), testData.size());
  ASSERT_FALSE(encodedData.empty()) << "Base64 kodlama başarısız.";
  std::vector<unsigned char> decodedData = base64Decode(encodedData);
  ASSERT_EQ(testData, std::string(decodedData.begin(), decodedData.end())) << "Base64 çözümlemesi başarısız.";
}

// HMAC hash testi - büyük/küçük harf duyarlılığı
TEST(HashPasswordWithHMACTest, CaseSensitivity) {
  std::string password = "Password";
  std::string salt = "salt";
  std::string hash1 = hashPasswordWithHMAC(password, salt);
  password = "password";
  std::string hash2 = hashPasswordWithHMAC(password, salt);
  EXPECT_NE(hash1, hash2);
}

/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char **argv) {
#ifdef ENABLE_LOCALEVENTPLANNER_TEST
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  return 0;
#endif
}
