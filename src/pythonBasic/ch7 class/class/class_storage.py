class Box1():
    """求立方体的类"""
    def __init__(self, length1, width1, height1):
        self.length = length1
        self.width = width1
        self.height = height1
    def volume(self):
        return self.length * self.width * self.height
class Box2(Box1):                                                         #继承Box1 定义子类Box2
    def __init__(self, length1, width1, height1):                         #子类重新定义__init__()
        super().__init__(length1, width1, height1)                        #super实现父类与子类的关联
        self.color = 'white'
        self.material = 'paper'
        self.type = 'fish'
    def area(self):
        re = self.length * self.height + self.length * self.width + self.height * self.width
        return re * 2