class Node:

    def __init__(self, label):
        self.label = label
        self.left = None
        self.right = None

    def getLabel(self):
        return self.label

    def setLabel(self, label):
        self.label = label

    def getLeft(self):
        return self.left

    def setLeft(self, left):
        self.left = left

    def getRight(self):
        return self.right

    def setRight(self, right):
        self.right = right


class BinarySearchTree:

    def __init__(self):
        self.root = None

    def insert(self, label):

        # cria um novo nó
        node = Node(label)

        # verifica se a árvore está vazia
        if self.empty():
            self.root = node
        else:

            # árvore não vazia, insere recursivamente

            dad_node = None
            curr_node = self.root

            while True:
                if curr_node != None:
                    dad_node = curr_node

                    # verifica se vai para esquerda ou direita
                    if node.getLabel() < curr_node.getLabel():
                        # vai para esquerda
                        curr_node = curr_node.getLeft()
                    else:
                        # vai para direita
                        curr_node = curr_node.getRight()
                else:

                    # se curr_node é None, então encontrou onde inserir
                    if node.getLabel() < dad_node.getLabel():
                        dad_node.setLeft(node)
                    else:
                        dad_node.setRight(node)

                    break  # sai do loop
        print("Nó " + str(label) + " criado!")

    def empty(self):
        if self.root == None:
            return True
        return False

    # mostra em pré-ordem (raiz-esquerda-direita)
    def show(self, curr_node):
        if curr_node != None:
            print('%d' % curr_node.getLabel(), end=' ')
            self.show(curr_node.getLeft())
            self.show(curr_node.getRight())

    def getRoot(self):
        return self.root

    def height(self, no):

        if no == None:
            return 0
        else:
            left = self.height(no.getLeft())
            right = self.height(no.getRight())

            if left > right:
                return (left + 1)
            else:
                return (right + 1)

    def quantNos(self, no):

        if no == None:
            return 0
        else:
            return 1 + self.quantNos(no.getLeft()) + self.quantNos(no.getRight())

    def quantLeaves(self, no):

        if no == None:
            return (0)
        elif ((no.getLeft()) == None and (no.getRight()) == None):
            return (1)
        else:
            return (self.quantLeaves(no.getLeft()) + self.quantLeaves(no.getRight()))

    def noRemove(self, r, v):
        if (r == None):
            return None
        elif (r.getLabel() > v):
            r.setLeft(self.noRemove(r.getLeft(), v))
        elif (r.getLabel() < v):
            r.setRight(self.noRemove(r.getRight(), v))
        else:
            #achou o nó a remover
            #nó sem filhos
            if (r.getLeft() == None and r.getRight() == None):
            
                r = None
                print("Nó " + str(v) + " deletado")
            
            #nó só tem filho à direita
            elif (r.getLeft() == None):
                t = r
                r = r.getRight()
                del t
                print("Nó " + str(v) + " deletado")
            
            #só tem filho à esquerda
            elif (r.getRight() == None):
            
                t = r
                r = r.getLeft()
                del t 
                print("Nó " + str(v) + " deletado")
            
            #nó tem os dois filhos
            else:
            
                f = r.getLeft()
                while (f.getRight() != None):
                
                    f = f.getRight()
                
                r.label = f.label #troca as informações
                f.label = v
                r.setLeft(self.noRemove(r.getLeft(), v))
                print("Nó " + str(v) + " deletado")
            
        
        return r
    

t = BinarySearchTree()
o = None

while o != 7:
    op = int(input("\n===============================\n1 - Inserir;\n2 - Altura;\n3 - Quantidade de nós;\n4 - Quantidade de folhas;\n5 - remover;\n6 - Imprimir arvore;\n7 - Sair.\n===============================\nSelecione a opção de escolha: "))

    if op == 1:
        #valor = int(input("Digite o valor do nó: "))
        # t.insert(valor)

        t.insert(8)
        t.insert(4)
        t.insert(2)
        t.insert(6)
        t.insert(1)
        t.insert(3)
        t.insert(5)
        t.insert(12)
        t.insert(10)
        t.insert(14)
        t.insert(11)
        t.insert(13)
        t.insert(15)

    elif op == 2:
        print("Altura da arvore: " + str(t.height(t.getRoot())))
    elif op == 3:
        print("Quantidade de nós: " + str(t.quantNos(t.getRoot())))
    elif op == 4:
        print("Quantidade de folhas: " + str(t.quantLeaves(t.getRoot())))
    elif op == 5:
        rm = int(input("Digite qual nó deseja remover: "))
        t.noRemove(t.getRoot(), rm)
    elif op == 6:
        t.show(t.getRoot())
    else:
        break
