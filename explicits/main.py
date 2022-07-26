from textual.app import App
from textual.widgets import Footer
from main_window import Main_Window
from textual import events
from header import Header
from dashboard import Dashboard

class Main(App):
    """Main Application to run and manage events ran by the user."""
    async def on_mount(self) -> None:
        # await self.view.dock()
        await self.view.dock(Header(), edge="top")
        await self.view.dock(Dashboard(), size=20, edge="left", name="dashboard")
        await self.view.dock(Footer(), edge="bottom")

    async def on_load(self, event: events.Load) -> None:
        await self.bind("q", "quit", "Quit")

    
Main.run(title="Explicits", log="explicits.log")
