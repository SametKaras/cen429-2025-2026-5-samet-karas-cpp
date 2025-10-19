# GitHub Project Board Setup Guide

## Step 1: Create New Project

1. Go to: https://github.com/SametKaras/cen429-2025-2026-5-samet-karas-cpp/projects
2. Click **"New project"** (green button, top right)
3. Select **"Board"** template
4. Click **"Create project"**

## Step 2: Configure Project

### Basic Information
- **Name:** Local Event Planner - Development
- **Description:** Project management board for secure event planner application
- **Visibility:** Private (or Public if you prefer)

### Configure Columns

Default columns: Todo, In Progress, Done

**Rename existing columns:**
1. Click **"⋯"** on column header → **Rename**
   - `Todo` → `Backlog`
   - Keep `In Progress`
   - Keep `Done`

**Add new columns** (Click "+ Add column" at the left):
1. Add **"Ready"** (between Backlog and In Progress)
2. Add **"In Review"** (between In Progress and Done)
3. Add **"Testing"** (between In Review and Done)

**Final column order:**
```
┌──────────┐  ┌───────┐  ┌─────────────┐  ┌───────────┐  ┌─────────┐  ┌──────┐
│ Backlog  │→│ Ready │→│ In Progress │→│ In Review │→│ Testing │→│ Done │
└──────────┘  └───────┘  └─────────────┘  └───────────┘  └─────────┘  └──────┘
```

## Step 3: Enable Auto-Add Workflow

1. Click **"⋯"** (three dots, top right) → **Settings**
2. Go to **"Workflows"** tab
3. Find **"Auto-add to project"** section
4. Toggle **ON**
5. Set filters:
   ```
   repo:SametKaras/cen429-2025-2026-5-samet-karas-cpp
   ```
6. Click **"Save"**

Now all new issues will be automatically added to the project!

## Step 4: Add Existing Issues

### Method A: Bulk Add (Recommended)

1. On your project board, click **"+ Add item"**
2. Click **"Add items from repository"**
3. Select repository: `SametKaras/cen429-2025-2026-5-samet-karas-cpp`
4. You'll see all 36 open issues
5. Press **Ctrl+A** (Windows) or **Cmd+A** (Mac) to select all
6. Click **"Add selected items"**

All 36 issues will be added to the Backlog column!

### Method B: Individual Add

1. Open any issue (e.g., #1)
2. On the right sidebar, find **"Projects"**
3. Click **"Add to projects"**
4. Select your project: "Local Event Planner - Development"

## Step 5: Organize Issues by Milestone

After adding all issues, you can organize them by milestone:

### M0 Issues (#1-6) → Move to "Ready" or "In Progress"
- Issue #1: Add Project Plan → **In Progress** (you're working on it!)
- Issue #2: Setup GitHub Project Board → **In Progress** (you're doing it now!)
- Issue #3-6: Move to **Ready**

### M1 Issues (#18-28) → Keep in "Backlog"
These will be worked on after M0 completion

### M2-M4 Issues → Keep in "Backlog"
Future milestones

## Step 6: Configure Views

### Add Milestone View

1. Click **"+"** next to "Board" tab
2. Select **"New view"**
3. Choose **"Board"** layout
4. Name it: "By Milestone"
5. Group by: **Milestone**
6. Save

Now you can switch between:
- **Board** (by status)
- **By Milestone** (grouped by M0, M1, M2, etc.)

### Add Priority View

1. Create another view
2. Name it: "By Priority"
3. Group by: **Labels** → Filter for `priority:*`
4. Sort by: Priority (P0 → P1 → P2 → P3)

## Step 7: Configure Status Field (Optional)

You can set automatic status updates:

1. Project Settings → **Fields**
2. Find **"Status"** field
3. Click **Edit**
4. Configure automation:
   - When issue opened → Set to **Backlog**
   - When issue assigned → Set to **Ready**
   - When PR opened → Set to **In Review**
   - When issue closed → Set to **Done**

## Tips & Best Practices

### Moving Cards
- Drag and drop issues between columns
- Or click issue → Change **Status** field

### Filtering
- Click **Filter** (top right)
- Filter by:
  - Milestone (M0, M1, M2, M3, M4)
  - Label (priority:P1, area:security, etc.)
  - Assignee
  - Status

### Keyboard Shortcuts
- `E` - Edit issue
- `X` - Archive card
- Arrow keys - Navigate between cards

### Milestone Progress
- Each milestone shows progress: "X of Y issues"
- Green bar shows completion percentage

## Verification Checklist

- [ ] Project created with Board template
- [ ] All 6 columns configured (Backlog → Ready → In Progress → In Review → Testing → Done)
- [ ] Auto-add workflow enabled
- [ ] All 36 open issues added to project
- [ ] M0 issues moved to appropriate columns
- [ ] Milestone view created
- [ ] Project is accessible and organized

## Screenshots Location

After setup, take screenshots and add them to:
- `docs/screenshots/github-project-board.png`
- Add to Issue #2 as proof of completion

## Next Steps

After completing this setup:
1. Close Issue #2 with comment: "Project board configured successfully"
2. Move to Issue #3: Setup CI and CodeQL
3. Update project board regularly as you progress

---

**Project URL:** https://github.com/users/SametKaras/projects/(number)

Replace `(number)` with your actual project number after creation.

