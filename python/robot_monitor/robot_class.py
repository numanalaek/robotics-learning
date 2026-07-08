class Robot:

    def __init__(self, name):
        self.name = name
        self.battery = 100

    def status(self):
        print(f"Robot: {self.name}")
        print(f"Battery: {self.battery}%")

robot = Robot("NUIN-AMR")

robot.status()
