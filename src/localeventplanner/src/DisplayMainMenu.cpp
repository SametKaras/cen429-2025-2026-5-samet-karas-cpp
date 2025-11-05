
/**
 * @file DisplayMainMenu.cpp
 *
 * @brief Provides functions for displaying the main menu and handling user input
 */

#include <iostream>
#include <string>
#include <vector>
#include "DisplayMainMenu.h"
#include "EventDetails.h"
#include "AttendeeManagement.h"
#include "UserAuthentication.h"
#include "sqlite3.h"

int step_counter = 0; // Adým sayacý





bool idssdds(int value) {
  if (value < 2) return false;

  for (int i = 2; i <= std::sqrt(value); ++i) {
    if (value % i == 0) return false;
  }

  return true;
}

void ttxczxfd() {
  std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 16, 25, 30 };
  std::vector<int> additionalData = { 12, 18, 22, 36, 45, 60, 72 };
  std::vector<int> finalData = { 101, 202, 303, 404, 505 };
  // Gereksiz deðiþkenler
  int evenCount = 0, oddCount = 0, primeCount = 0;
  int sumMultiplesOfFive = 0, perfectSquareCount = 0;
  int divisibleByThreeCount = 0, digitSumGreaterThanTen = 0;
  long long unnecessaryComputationSum = 0, totalIterations = 0;
  long long specialConditionCount = 0, modSevenCount = 0;
  double accumulatedSquareRoots = 0.0;
  int totalDigitProduct = 1;
  // Gereksiz deðiþkenler
  int a = 0;
  int b = 1;
  int c = 2;
  int d = 3;
  int uselessCalculation1 = 0;
  int uselessCalculation2 = 0;
  int uselessCalculation3 = 0;

  for (int value : data) {
    totalIterations++;
    // Gereksiz iþlemler
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
    a = a + 1 - 1 + 2 - 2; // Daha fazla gereksiz iþlem
    b = b * 2 / 2 + 5 - 5;
    c = c + a - b + 3 - 3;
    d = d * 4 / 4 - c + 6 - 6;

    if (value % 2 == 0) {
      evenCount++;
      continue;
    }

    oddCount++;

    if (idssdds(value)) {
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
  // Daha fazla gereksiz deðiþken
  int p = 10;
  int q = 20;
  int r = 30;
  int s = 40;
  int t = 50;
  p = p + q - r + s - t;
  q = q * 2 - p + r - s + t;
  r = r * 3 / 3 + q - p;
}

/**
*
* @brief Clears the console screen
*
*/
LOCAL_EVENT_PLANNER_API void clearConsole() {
#ifdef _WIN32
  ttxczxfd();
  system("cls"); // Windows platformu için konsolu temizle
#else
  system("clear"); // Linux ve MacOS platformlarý için konsolu temizle
#endif
}
