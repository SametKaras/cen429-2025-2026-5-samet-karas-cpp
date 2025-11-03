/**
 * @file localeventplannerapp.cpp
 * @brief Main application for Local Event Planner
 *
 * This program provides user authentication and event management features
 */

#include <iostream>
#include <string>
#include "../../localeventplanner/header/UserAuthentication.h"
#include "../../localeventplanner/header/EventDetails.h"
#include "../../localeventplanner/header/SessionEncryption.h"

int main() {
  std::cout << "=================================\n";
  std::cout << "  Local Event Planner Application\n";
  std::cout << "=================================\n\n";

  // Setup session encryption
  if (!setupSessionEncryption()) {
    std::cerr << "Session encryption setup failed!\n";
    return 1;
  }

  std::cout << "Session encryption initialized successfully.\n\n";
  // User authentication menu
  int choice;
  bool authenticated = false;

  while (!authenticated) {
    std::cout << "\n--- User Authentication ---\n";
    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "3. Guest Mode\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        authenticated = loginUser();
        break;

      case 2:
        registerUser();
        std::cout << "\nPlease login with your new account.\n";
        break;

      case 3:
        setGuestMode(true);
        std::cout << "\nEntering as guest...\n";
        authenticated = true;
        break;

      case 0:
        std::cout << "Exiting application...\n";
        return 0;

      default:
        std::cout << "Invalid choice! Please try again.\n";
    }
  }

  // Event management menu
  if (authenticated) {
    bool running = true;

    while (running) {
      std::cout << "\n\n--- Event Management ---\n";
      std::cout << "1. Create Event\n";
      std::cout << "2. Manage Events\n";
      std::cout << "3. List All Events\n";
      std::cout << "0. Exit\n";
      std::cout << "Enter your choice: ";
      std::cin >> choice;

      switch (choice) {
        case 1:
          createEvent();
          break;

        case 2:
          manageEvents();
          break;

        case 3:
          manageEvents();
          break;

        case 0:
          std::cout << "Exiting application...\n";
          running = false;
          break;

        default:
          std::cout << "Invalid choice! Please try again.\n";
      }
    }
  }

  return 0;
}
