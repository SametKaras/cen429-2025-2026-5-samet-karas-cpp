#ifndef FEEDBACK_COLLECTION_H
#define FEEDBACK_COLLECTION_H

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

LOCAL_EVENT_PLANNER_API void feedbackCollection();
LOCAL_EVENT_PLANNER_API void gatherFeedback();
LOCAL_EVENT_PLANNER_API void viewFeedbacks();
LOCAL_EVENT_PLANNER_API sqlite3* openFeedbackDatabase();
#ifdef __cplusplus
}

#endif

#endif
