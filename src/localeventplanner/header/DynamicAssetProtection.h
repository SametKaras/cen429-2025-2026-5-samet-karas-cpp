#ifndef DYNAMIC_ASSET_PROTECTION_H
#define DYNAMIC_ASSET_PROTECTION_H

#ifdef LOCAL_EVENT_PLANNER_LIB_EXPORTS
  #define LOCAL_EVENT_PLANNER_API __declspec(dllexport)  // DLL oluşturulurken dışa aktarım
#else
  #define LOCAL_EVENT_PLANNER_API __declspec(dllimport)  // DLL kullanılırken içe aktarım
#endif

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

LOCAL_EVENT_PLANNER_API std::string getEncryptedDeviceFingerprint();

#ifdef __cplusplus
}
#endif

LOCAL_EVENT_PLANNER_API std::string base64Encode(const unsigned char *buffer, size_t length);

#endif // DYNAMIC_ASSET_PROTECTION_H
