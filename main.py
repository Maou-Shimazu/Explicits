import pytermgui as ptg
from explicits.main_window import Main_Window
# import explicits.player_info as exp
import explicits.dashboard as dsb 

def main():
    with ptg.WindowManager() as manager:
        window = ptg.Window(
            "[wm-title]Explicits",
            "",
            ["Exit", lambda *_: Main_Window.quit(manager)],
            ["Dashboard", lambda *_: dsb.Dashboard()],
        ).center()
        manager.add(window)
        manager.run()

if __name__ == "__main__":
    main()
