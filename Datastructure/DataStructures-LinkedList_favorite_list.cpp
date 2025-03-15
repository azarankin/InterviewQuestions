#include <iostream>
#include <set>

using namespace std;

// Data structure for a favorite item
struct FavoriteItem {
    int id;
    int value;
    int priority;

    bool operator<(const FavoriteItem& other) const {
        return priority < other.priority; // Used for comparison inside the set
    }
};

// Class for managing the favorites list
class FavoriteList {
private:
    int MAX_SIZE;
    set<FavoriteItem> tree;  // Sorted tree based on priority

public:
    explicit FavoriteList(int maxSize) : MAX_SIZE(maxSize) {}

    void addFavorite(int id, int value, int priority)
    {
        if (tree.size() >= MAX_SIZE)
        {
            removeLowestPriority();  // Remove an item if exceeding the maximum size
        }
        tree.insert({ id, value, priority });
    }

    void removeLowestPriority()
    {
        if (!tree.empty())
        {
            cout << "Removed item with ID: " << tree.begin()->id << " (Priority: " << tree.begin()->priority << ")\n";
            tree.erase(tree.begin()); // Remove the item with the lowest priority
        }
    }

    void printFavorites()
    {
        cout << "Favorite List:\n";
        for (const auto& item : tree) {
            cout << "ID: " << item.id << ", Value: " << item.value << ", Priority: " << item.priority << "\n";
        }
    }
};

int main_FavoriteList()
{
    FavoriteList favs(3); // List with a maximum of 3 favorite items

    favs.addFavorite(1, 100, 5);
    favs.addFavorite(2, 200, 3);
    favs.addFavorite(3, 300, 8);
    favs.printFavorites();

    cout << "\nAdding another item (will trigger removal of lowest priority)...\n";
    favs.addFavorite(4, 400, 4); // This will remove the element with the lowest priority
    favs.printFavorites();

    return 0;
}
