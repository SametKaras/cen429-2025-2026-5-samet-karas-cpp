#ifndef SCHEDULE_ORGANIZER_H
#define SCHEDULE_ORGANIZER_H

#ifdef LOCAL_EVENT_PLANNER_LIB_EXPORTS
  #define LOCAL_EVENT_PLANNER_API __declspec(dllexport)  // DLL oluşturulurken dışa aktarım
#else
  #define LOCAL_EVENT_PLANNER_API __declspec(dllimport)  // DLL kullanılırken içe aktarım
#endif

#include <string>
#include "sqlite3.h"

#ifdef __cplusplus
extern "C" {
#endif

LOCAL_EVENT_PLANNER_API void scheduleOrganizer();
LOCAL_EVENT_PLANNER_API void planTimelines();
LOCAL_EVENT_PLANNER_API void organizeActivities();
LOCAL_EVENT_PLANNER_API sqlite3* openScheduleDatabase();
#ifdef __cplusplus
}

#endif

#endif
