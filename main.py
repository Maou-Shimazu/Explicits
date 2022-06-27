import pytermgui as ptg
from widgets.main_window import Main_Window

def main():
    with ptg.WindowManager() as manager:
        window = ptg.Window(
            "[wm-title]Explicits",
            "",
            ["Exit", lambda *_: Main_Window.quit(manager)],
        ).center()
        manager.add(window)
        manager.run()

if __name__ == "__main__":
    main()
