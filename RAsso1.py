class hashTable:
    def __init__(self, size):
        self.m = size
        self.hashTable = None * self
        self.elecount = 0
        
    def hashFunction(self, key):
            return key % self.m

    def isFUll(self):
        return self.elecount == self.m   

    def linerProbe(self, key ,data):
        index = self.hashFunction(key)
        while self.hashTable[index] is not None:
            index = (index+ 1) % self.m
        self.hashTable[index] = [key, data]
        self.elecount += 1
        return index
    
    def quadProbe(self, key, data):
        index =  self.hashFunction(key)
        i = 0
        while self.hashTable[index] is not None:
            index = (index + i * 2) % self.m
            i += 1
        self.hashTable[index] = [key, data]
        self.elecount += 1
        return index
    
    def search(self, key, data , probe_method):
        index = self.hashFunction(key)
        i = 0
        while self.hashTable[index] is not None:
            if self.hashTable[index] == [key , data]:
                return index
            if probe_method == "linear":
                index = (index + 1) % self.m
            elif probe_method == "quadratic":
                index = (index + i * 2)% self.m
        return None
    
def menu():
    size = int(input("Enter size of hash table: "))
    obj  = hashTable(size)
    
    while True:
        print("************************")
        print("1. Linear Probe")
        print("2. Quadratic Probe")
        print("3. Exit")
        print("************************")

        choice = int(input("Enter Choice: "))

        if choice == 1 or choice == 2:
            probe_method = "linear" if choice == 1 else "quadratic"
            sub_menu(obj, probe_method)
        elif choice == 3:
            break
        else:
            print("Invalid choice. Please try again.")

def sub_menu(obj, probe_method):
    while True:
        print("** Insert **")
        print("** Search **")
        print("** Exit **")

        sub_choice = int(input("Enter your choice: "))

        if sub_choice == 1:
            key = int(input("Enter phone number: "))
            name = input("Enter name: ")
            if obj.isFull():
                print("Table is full.")
            else:
                if probe_method == "linear":
                    index = obj.linearProbe(key, name)
                else:
                    index = obj.quadraticProbe(key, name)
                print("Data inserted at index", index)
        elif sub_choice == 2:
            key = int(input("Enter key to be searched: "))
            name = input("Enter name: ")
            index = obj.search(key, name, probe_method)
            if index is None:
                print("Key not found.")
            else:
                print("Key found at index", index)
        elif sub_choice == 3:
            break
        else:
            print("Invalid choice. Please try again.")

menu()
