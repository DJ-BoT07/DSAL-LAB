class Set:
    def __init__(self, elementCount):
        self._s = []
        for i in range(elementCount):
            e = int(input("Enter Element {}: ", format(i+1)))
            self.add(e)
            
    def get_set(self):
        return self._s
    
    def __len__(self):
        return len(self._s)
    
    def __contains__(self, e):
        return e in self._s
    
    def isEmptyt(self):
        return len(self._s) == 0
    
    def add(self, e):
        if e not in self.get_set():
            self._s.append(e)
            
    def remove(self, e):
        if e in self.get_set():
            self.get_set().remove()
            
    def __eq__(self, setB):
        if len(self) == len(setB):
            return True
        else:
            return False
        
    def isSubset(self,setB):
        for e in setB.get_set():
            if e not in self.get_set( ):
                return False
        return True
    
    def isProperSubset(self, setB):
        if self.isSubSet(setB) and not setB.isSubSet(self):
            return True
        return False
    
    def union(self, setB):
        newSet = self
        for e in setB:
            if e not in self.get_set( ):
                newSet.add(e)
        return newSet
    
    def intersect(self, setB):
        newSet = Set(0)
        for item_self in self.get_set():
            for item_setB in setB.get_set():
                if item_self == item_setB
                    newSet.add(item_self)
        return newSet
    
    def difference(self , setB):
        newSet = Set(0)
        for e in self.get_set():
            if e not in setB.get_set():
                newSet(e)
                
        return newSet
            
            
    def __iter__( self ):
        return iter(self._s)
