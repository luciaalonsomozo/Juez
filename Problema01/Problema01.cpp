
/*@ <answer>
 *
 * Nombre y Apellidos: Lucía Alonso Mozo
 *
 *@ </answer> */

#include <cassert>
#include <iostream>
#include <memory>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <tuple>
#include <climits>

using namespace std;

template <class T> class BinTree {
public:
    BinTree() : root_node(nullptr) {}

    BinTree(const T& elem)
        : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

    BinTree(const BinTree& left, const T& elem, const BinTree& right)
        : root_node(std::make_shared<TreeNode>(left.root_node, elem,
            right.root_node)) {}

    bool empty() const { return root_node == nullptr; }

    const T& root() const {
        assert(root_node != nullptr);
        return root_node->elem;
    }

    BinTree left() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->left;
        return result;
    }

    BinTree right() const {
        assert(root_node != nullptr);
        BinTree result;
        result.root_node = root_node->right;
        return result;
    }

    void display(std::ostream& out) const { display_node(root_node, out); }

private:
    // Las definiciones de TreeNode y NodePointer dependen recursivamente
    // la una de la otra. Por eso declaro 'struct TreeNode;' antes de NodePointer
    // para que el compilador sepa, cuando analice la definiciÛn de NodePointer,
    // que TreeNode va a ser definida m·s adelante.

    struct TreeNode;
    using NodePointer = std::shared_ptr<TreeNode>;

    struct TreeNode {
        TreeNode(const NodePointer& left, const T& elem, const NodePointer& right)
            : elem(elem), left(left), right(right) {}

        T elem;
        NodePointer left, right;
    };

    NodePointer root_node;

    static void display_node(const NodePointer& root, std::ostream& out) {
        if (root == nullptr) {
            out << ".";
        }
        else {
            out << "(";
            display_node(root->left, out);
            out << " " << root->elem << " ";
            display_node(root->right, out);
            out << ")";
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const BinTree<T>& tree) {
    tree.display(out);
    return out;
}

template <typename T> BinTree<T> read_tree(std::istream& in) {
    char c;
    in >> c;
    if (c == '.') {
        return BinTree<T>();
    }
    else {
        assert(c == '(');
        BinTree<T> left = read_tree<T>(in);
        T elem;
        in >> elem;
        BinTree<T> right = read_tree<T>(in);
        in >> c;
        assert(c == ')');
        BinTree<T> result(left, elem, right);
        return result;
    }
}

template <typename T>
int numero_nodos(const BinTree<T>& tree) {

    // Caso base: hoja
    if (tree.left().empty() && tree.right().empty())
        return 1;

    else {
        int nodosIzq = (tree.left().empty() ? 0 : numero_nodos(tree.left()));
        int nodosDcha = (tree.right().empty() ? 0 : numero_nodos(tree.right()));

        return (nodosIzq + nodosDcha + 1);
    }
}

template <typename T>
int altura(const BinTree<T>& tree) {
    // Altura es el maximo de los niveles, o la longitud de la rama mas larga.

    if (tree.left().empty() && tree.right().empty())
        return 1;

    else {
        int alturaIzq = (tree.left().empty() ? 0 : altura(tree.left()) + 1);
        int alturaDcha = (tree.right().empty() ? 0 : altura(tree.right()) + 1);

        return max(alturaIzq, alturaDcha);
    }
}



/*@ <answer>

  Comentario general sobre la solucion: en el caso recursivo, basta con guardar si el lado izquierdo
  y el lado derecho son AVL, y ademas preguntar si en ese momento, el arbol completo en el que
  estas es AVL tambien.

  Coste de la solucion: en caso de que el arbol este equilibrado, la recurrencia seria T(n/2) + T(n/2) = 2T(n/2),
  que pertenece al orden de O(n).

  Si el arbol no esta equilibrado, la recurrencia seria T(n_i) + T(n_d) + k, que pertenece al orden de O(n)

  Luego en cualquier caso, la funcion tiene orden lineal respecto al numero de elementos del arbol.

 @ </answer> */


 //@ <answer>


// El primer parametro es si es AVL o no
// El segundo es la altura total
// El tercero es el minimo del lado izquierdo del arbol
// El cuarto es el maximo del lado derecho del arbol 
tuple <bool, int, int, int> AVL(BinTree<int> const& tree) {

    // Caso base 1
    if (tree.empty())
        return { true, 0, INT_MAX, INT_MIN};

    // Caso base 2 (hoja)
    else if (tree.left().empty() && tree.right().empty())
        return { true, 1, tree.root(), tree.root() };

    else {
        auto [AVLIzq, hi, mii, mai] = AVL(tree.left());
        auto [AVLDer, hd, mid, mad] = AVL(tree.right());
        bool booleano = AVLIzq && AVLDer && (mai < tree.root()) && (tree.root() < mid) && abs(hi - hd)<= 1;
        int altura = 1 + max(hi, hd);
        int elementoMinimo = min(mii, tree.root());
        int elementoMaximo = max(mad, tree.root());
        return { booleano, altura , elementoMinimo ,  elementoMaximo};
    }
}

template <typename T>
bool esAVL(BinTree<T> const& tree) {
    auto [booleano, numDesdencientes, maximo, minimo] = AVL(tree);
    return booleano;
}

void resuelveCaso()
{
    BinTree<int> tree = read_tree<int>(cin);

    cout << (esAVL(tree) ? "SI\n" : "NO\n");
}

//@ </answer>

//  Lo que se escriba dejado de esta lÌnea ya no forma parte de la soluciÛn.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
