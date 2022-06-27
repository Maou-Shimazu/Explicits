
import pytermgui as ptg

class Main_Window(ptg.WindowManager):   

    def dashboard(self):
        pass
    def player_information(self):
        pass

    def quit(self) -> None:
        """Quit Modal"""
        modal = ptg.Window(
            "[app.title]Are you sure you wannt to quit?",
            "",
            ptg.Container(
                ptg.Splitter(
                    ptg.Button("Yes", lambda *_: self.stop()),
                    ptg.Button("No", lambda *_: modal.close())
                ),
            ),
        ).center()

        modal.select(1)
        self.add(modal)
