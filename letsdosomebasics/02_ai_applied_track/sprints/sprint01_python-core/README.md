# Sprint01 — Python Core Without AI (D1-7, 2hr/day)

Goal: Write basic Python cold, no AI. Since you can READ, we force WRITE.

Rule: No Copilot/ChatGPT for logic. Syntax error → ask me free. Logic stuck → hint = Assisted.

## Daily plan

**D1 (2hr): Lists/Dicts/Loops**
- Watch: Corey Schafer Lists/Dicts (1hr, 1.5x) + Data School pandas-intro teaser (30m)
- Task (1hr, no AI): `s01_d1.py` — given list of dicts `[{"name":"a","score":10},...]`, return avg, max-scorer name, filter score>15. Write 3 functions. Run.
- Done = file runs + you explain each loop aloud.

**D2: Strings + Files**
- Watch: Corey Schafer strings/files (45m)
- Task: read csv by hand (open, split, no pandas), count rows, find column max. `s01_d2.py`.

**D3: Functions + Scope**
- Watch: Corey Schafer functions/scope (45m)
- Task: refactor D1+D2 into importable functions with `if __name__=="__main__"`. No global mutation.

**D4: OOP Basics**
- Watch: Corey Schafer OOP 1-2 (1hr)
- Task: `Dataset` class with `load(), mean(col), filter_gt(col,val)`. Instantiate + use.

**D5: Errors + Debugging**
- Watch: Corey Schafer try/except + Luke Barousse debugging bit (45m)
- Task: break D4 on purpose (empty file, missing col), add try/except + meaningful messages. Show traceback you fixed.

**D6: Mini Task No-AI (exam)**
- No video. 2hr: I give you a fresh task in chat (e.g. word-count + top-k). You code live, I test hidden.

**D7 SUN: Revise only**
- Re-type D1, D4 from memory (no look). Note what you forgot in PROGRESS_AI.md. No new video.

## Carry rule
Missed day shifts forward. Example: miss D3 → D3 becomes tomorrow, sprint ends D8. Never skip.
Log daily: Done? AI used? Result.

Next: report D1 when done, I verify by running your file + 2 questions.
