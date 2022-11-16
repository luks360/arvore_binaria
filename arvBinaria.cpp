#include <iostream>
#include <Windows.h>
using namespace std;

class No
{
public:
    No *left, *right;
    int key;

    No(int key)
    {
        this->key = key;
        left = NULL;
        right = NULL;
    }

    int getKey()
    {
        return key;
    }

    No *getLeft()
    {
        return left;
    }

    No *getRight()
    {
        return right;
    }

    void setLeft(No *no)
    {
        left = no;
    }
    void setRight(No *no)
    {
        right = no;
    }
};

class Tree
{
private:
    No *root;

public:
    Tree()
    {
        root = NULL;
    }

    No *getRoot()
    {
        return root;
    }

    void insert(int key)
    {
        if (root == NULL)
            root = new No(key);
        else
        {
            insertAux(root, key);
        }
        cout<<"Nó " << key << " criado"<<endl;
    }

    void insertAux(No *no, int key)
    {
        if (key < no->getKey())
        {
            if (no->getLeft() == NULL)
            {
                No *new_no = new No(key);
                no->setLeft(new_no);
            }
            else
            {
                insertAux(no->getLeft(), key);
            }
        }
        else if (key > no->getKey())
        {
            if (no->getRight() == NULL)
            {
                No *new_no = new No(key);
                no->setRight(new_no);
            }
            else
            {
                insertAux(no->getRight(), key);
            }
        }
    }

    void inOrder(No *no)
    {
        if (no != NULL)
        {
            inOrder(no->getLeft());
            cout << no->getKey() << " | ";
            inOrder(no->getRight());
        }
    }

    int height(No *no)
    {

        if (no == NULL)
            return 0;
        else
        {
            /* compute the depth of each subtree */
            int left = height(no->getLeft());
            int right = height(no->getRight());

            /* use the larger one */
            if (left > right)
                return (left + 1);
            else
                return (right + 1);
        }
        cout << endl;
    }

    int quantNos(No *no)
    {
        if (no == NULL)
            return 0;
        else
            return 1 + quantNos(no->getLeft()) + quantNos(no->getRight());

        cout << endl;
    }

    int quantLeaves(No *no)
    {
        if (no == NULL)
            return (0);
        else if ((no->getLeft()) == NULL && (no->getRight()) == NULL)
            return (1);
        else
            return (quantLeaves(no->getLeft()) + quantLeaves(no->getRight()));
    }

    No* noRemove(No* r, int v)
    {
        if (r == NULL)
            return NULL;
        else if (r->getKey() > v)
            r->setLeft(noRemove(r->getLeft(), v));
        else if (r->getKey() < v)
            r->setRight(noRemove(r->getRight(), v));
        else
        {   /* achou o nó a remover */
            /* nó sem filhos */
            if (r->getLeft() == NULL && r->getRight() == NULL)
            {
                free(r);
                r = NULL;
                cout<<"Nó " << v << " deletado"<<endl;
            }
            /* nó só tem filho à direita */
            else if (r->getLeft() == NULL)
            {
                No* t = r;
                r = r->getRight();
                free(t);
                cout<<"Nó " << v << " deletado"<<endl;
            }
            /* só tem filho à esquerda */
            else if (r->getRight() == NULL)
            {
                No* t = r;
                r = r->getLeft();
                free(t);
                cout<<"Nó " << v << " deletado"<<endl;
            }
            /* nó tem os dois filhos */
            else
            {
                No* f = r->left;
                while (f->right != NULL)
                {
                    f = f->right;
                }
                r->key = f->key; /* troca as informações */
                f->key = v;
                r->left = noRemove(r->left, v);
                cout<<"Nó " << v << " deletado"<<endl;
            }
        }
        return r;
    }
};

int main()
{
SetConsoleOutputCP(65001);

    Tree tree;
    int o, x;

    while (o != 7)
    {
        cout << "===============================\n";
        cout << "1 - Inserir;\n";
        cout << "2 - Altura;\n";
        cout << "3 - Quantidade de nós;\n";
        cout << "4 - Quantidade de folhas;\n";
        cout << "5 - remover;\n";
        cout << "6 - Imprimir arvore;\n";
        cout << "7 - Sair.\n";
        cout << "===============================\n";
        cout << "Selecione a opção de escolha: ";
        cin >> o;
        switch (o)
        {
        case 1:
            /* cout << "Digite o valor: ";
            cin >> x;
            tree.insert(x);
            break; */

            tree.insert(8);
            tree.insert(4);
            tree.insert(2);
            tree.insert(6);
            tree.insert(1);
            tree.insert(3);
            tree.insert(5);
            tree.insert(12);
            tree.insert(10);
            tree.insert(14);
            tree.insert(11);
            tree.insert(13);
            tree.insert(15);
            break;

        case 2:
            cout << "Altura da arvore: " << tree.height(tree.getRoot()) << endl;
            break;

        case 3:
            cout << "Quantidade de nós: " << tree.quantNos(tree.getRoot()) << endl;
            break;

        case 4:
            cout << "Quantidade de folhas: " << tree.quantLeaves(tree.getRoot()) << endl;
            break;

        case 5:
            int rm;
            cout<<"Digite qual nó deseja remover: ";
            cin>> rm;
            tree.noRemove(tree.getRoot(), rm);
            break;

        case 6:
            cout << "Imprimindo arvore em ordem \n";
            tree.inOrder(tree.getRoot());
            cout <<endl;
            cout<<"Raiz: " << tree.getRoot()->getKey()<<endl;
            break;

        default:
            break;
        }
    }
}