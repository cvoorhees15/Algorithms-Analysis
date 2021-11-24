class Hotel(object):
    name = ""
    xPt = 0
    yPt = 0
    capacity = 0

    # Constructor
    def __init__(self, name, xPt, yPt):
        self.name = name
        self.xPt = xPt
        self.yPt = yPt
        self.coordinate = (xPt, yPt)
        self.distance = []
