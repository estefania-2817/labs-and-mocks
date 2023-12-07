#include <iostream>
#include <string>
#include <vector>

/*
 * Item is a class that represents items that might
 * be in a supermarket. An Item has the following 
 * properties: price, origin, name, and type. 
 * (See the enum PType for the available types.)
 */

using namespace std;

enum PType{
    FROZEN,
    FRESH,
    SNACK,
    BAKED,
    SWEET,
    DAIRY,
    OTHER
};

class Item{

private:
    string name;
    string origin;
    double price;
    PType type;

public:
    // Constructors
    Item(){};

    Item(string name, string origin, double price, PType type){
        this->name = name;
        this->origin = origin;
        this->price = price;
        this->type = type;
    }

    // Getters
    string getName() {return name;}
    string getOrigin() {return origin;}
    double getPrice() {return price;}
    PType getType() {return type;}

    // Setters
    void setName(string name) {this->name = name;}
    void setOrigin(string origin) {this->origin = origin;}
    void setPrice(double price) {this->price = price;}
    void setType(PType type) {this->type = type;}

    // Instance Methods
    bool equals(Item otherItem){
        return this->getName() == otherItem.getName() &&
               this->getOrigin() == otherItem.getOrigin() &&
               this->getPrice() == otherItem.getPrice() &&
               this->getType() == otherItem.getType();
    }
    // Tester Methods (DO NOT REMOVE)
    static string enumToString(PType type){
        switch(type){
        case FROZEN:
            return "FROZEN";
        case FRESH:
            return "FRESH";
        case SNACK:
            return "SNACK";
        case BAKED:
            return "BAKED";
        case SWEET:
            return "SWEET";
        case DAIRY:
            return "DAIRY";
        case OTHER:
            return "OTHER";
        }
        return "";
    }

    void printAttr(){
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << "Item object: ";
        cout << "Name: "; 
        cout << name;
        cout << ", Origin: ";
        cout << origin;
        cout << ", Price: ";
        cout << price;
        cout << ", Type: ";
        cout << enumToString(type);
        cout << endl;
    }
    static void print4FirstItemVector(vector<Item> v){
        if(v.empty()) cout << endl;
        if(v.size() >= 1) v.at(0).printAttr();
        if(v.size() >= 2) {
            cout << "\t";
            v.at(1).printAttr();
        }
        if(v.size() >= 3) {
            cout << "\t";
            v.at(2).printAttr();
        }
        if(v.size() >= 4) {
            cout << "\t";
            v.at(3).printAttr();
        }
    }
    // Methods Declared
    static double priceOfList(vector<Item> itemList); 
    static int originCount(string origin, vector<Item> itemList); 
    static vector<Item> getTypeList(PType type, vector<Item> itemList); 
    static Item firstItemOccurrence(double price, vector<Item> itemList); 
    static double mostExpensiveItemPerType(PType type, vector<Item> itemList); 
    static void removeItemWithType(PType type, vector<Item> &itemList);
    static bool noDuplicates(vector<Item> itemList); 
    static bool isItemPerTypeOriginBudget(PType type, string origin, double budget, vector<Item> itemList); 
    static PType mostExpensiveType(vector<Item> itemList); 
    static string listItemPerType(PType type, vector<Item> itemList); 
    static vector<Item> difference(vector<Item> v1, vector<Item> v2);

};

int main(void){
    Item i1("Froot Loops", "USA", 3.98, SWEET);
    Item i2("Lettuce", "USA", 1.48, FRESH);
    Item i3("Frozen Pizza", "Italia", 9.86, FROZEN);
    Item i4("Cream", "USA", 2.99, DAIRY);
    Item i5("Greek Yogurt", "Greece", 5.25, DAIRY);
    Item i6("Parmigiano Reggiano", "Italia", 27.88, DAIRY);
    Item i7("Croissant", "France", 4.58, BAKED);
    Item i8("Takis", "Mexico", 1.96, SNACK);
    Item i9("Apple", "USA", 1.58, FRESH);
    Item i10("Beef Jerky", "USA", 9.84, SNACK);

    vector<Item> emptyList = {};
    vector<Item> itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    vector<Item> itemList2 = {i1, i4, i5, i6, i7, i10};
    vector<Item> itemList3 = {i3, i4, i8, i9, i10};
    vector<Item> itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    vector<Item> itemList5 = {i1, i9, i10};

    cout << "EXAM 2 TESTER" << endl;
    cout << endl;

   /*
     *
     * Testing Method: priceOfList
     *
     */

    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "Price of List 1: ";
    // cout << Item::priceOfList(itemList1) << endl;
    // cout << "Price of List 2: ";
    // cout << Item::priceOfList(itemList2) << endl;
    // cout << "Price of List 3: ";
    // cout << Item::priceOfList(itemList3) << endl;
    // cout << "Price of List 4: ";
    // cout << Item::priceOfList(itemList4) << endl;
    // cout << "Price of List 5: ";
    // cout << Item::priceOfList(itemList5) << endl;
    // cout << "Price of Empty List: ";
    // cout << Item::priceOfList(emptyList) << endl;
    // cout << endl;

    /*
     *
     * Testing Method: originCount
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "USA Origin Count List 1: ";
    // cout << Item::originCount("USA",itemList1) << endl;
    // cout << "France Origin Count List 1: ";
    // cout << Item::originCount("France",itemList1) << endl;
    // cout << "Italia Origin Count List 1: "; 
    // cout << Item::originCount("Italia",itemList1) << endl;
    // cout << "Greece Origin Count List 1: ";
    // cout << Item::originCount("Greece",itemList1) << endl;
    // cout << "Mexico Origin Count List 1: ";
    // cout << Item::originCount("Mexico",itemList1) << endl;
    // cout << "USA Origin Count Empty List: ";
    // cout << Item::originCount("USA",emptyList) << endl;
    // cout << endl;

    /*
     *
     * Testing Method: getTypeList
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "FROZEN type List from List 2: ";
    // Item::print4FirstItemVector(Item::getTypeList(FROZEN,itemList2)); 
    // cout << "FRESH type List from List 1: ";
    // Item::print4FirstItemVector(Item::getTypeList(FRESH,itemList1)); 
    // cout << "SNACK type List from List 3: ";
    // Item::print4FirstItemVector(Item::getTypeList(SNACK,itemList3));
    //  cout << "BAKED type List from List 5: ";
    // Item::print4FirstItemVector(Item::getTypeList(BAKED,itemList5));
    // cout << "SWEET type List from List 2: ";
    // Item::print4FirstItemVector(Item::getTypeList(SWEET,itemList2));
    // cout << "DAIRY type List from List 4: ";
    // Item::print4FirstItemVector(Item::getTypeList(DAIRY,itemList4));
    // cout << "OTHER type List from List 1: ";
    // Item::print4FirstItemVector(Item::getTypeList(OTHER,itemList1));
    // cout << "DAIRY type List from Empty List: ";
    // Item::print4FirstItemVector(Item::getTypeList(DAIRY,emptyList));
    // cout << endl;

    /*
     *
     * Testing Method: firstItemOccurrence
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "First Item occurence with a 0.50 budget from List 1: ";
    // Item::firstItemOccurrence(0.50, itemList1).printAttr(); 
    // cout << "First Item occurence with a 0 budget from List 2: ";
    // Item::firstItemOccurrence(0, itemList2).printAttr(); 
    // cout << "First Item occurence with a 15.00 budget from List 1: ";
    // Item::firstItemOccurrence(15.00, itemList1).printAttr(); 
    // cout << "First Item occurence with a 25.75 budget from List 4: ";
    // Item::firstItemOccurrence(25.75, itemList4).printAttr(); 
    // cout << "First Item occurence with a 9.86 budget from List 1: ";
    // Item::firstItemOccurrence(9.86, itemList1).printAttr(); 
    // cout << "First Item occurence with a 9.86 budget from Empty List: ";
    // Item::firstItemOccurrence(9.86, emptyList).printAttr(); 
    // cout << endl;

    /*
     *
     * Testing Method: mostExpensiveItemPerType
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "Price of Most Expensive SWEET item in List 1: ";
    // cout << Item::mostExpensiveItemPerType(SWEET, itemList1) << endl;
    // cout << "Price of Most Expensive BAKED item in List 2: ";
    // cout << Item::mostExpensiveItemPerType(BAKED, itemList2) << endl;
    // cout << "Price of Most Expensive FRESH item in List 3: ";
    // cout << Item::mostExpensiveItemPerType(FRESH, itemList3) << endl;
    // cout << "Price of Most Expensive FROZEN item in List 4: "; 
    // cout << Item::mostExpensiveItemPerType(FROZEN, itemList4) << endl;
    // cout << "Price of Most Expensive OTHER item in List 5: "; 
    // cout << Item::mostExpensiveItemPerType(OTHER, itemList5) << endl;
    // cout << "Price of Most Expensive SWEET item in empty list: ";
    // cout << Item::mostExpensiveItemPerType(SWEET, emptyList) << endl;
    // cout << endl;

    /*
     *
     * Testing Method: removeItemWithType
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // Item::removeItemWithType(FROZEN, itemList1);
    // cout << "List 1 with the first FROZEN item removed called: ";
    // Item::print4FirstItemVector(itemList1);

    // Item::removeItemWithType(FROZEN, itemList1);
    // cout << "List 1 with the first FROZEN item removed called: ";
    // Item::print4FirstItemVector(itemList1);

    // Item::removeItemWithType(FRESH, itemList1);
    // cout << "List 1 with the first FRESH item removed called: ";
    // Item::print4FirstItemVector(itemList1); 
    
    // Item::removeItemWithType(SNACK, itemList1);
    // cout << "List 1 with the first SNACK item removed called: ";
    // Item::print4FirstItemVector(itemList1);

    // Item::removeItemWithType(DAIRY, itemList1);
    // cout << "List 1 with the first DAIRY item removed called: ";
    // Item::print4FirstItemVector(itemList1);
    
    // Item::removeItemWithType(FROZEN, emptyList);
    // cout << "Empty list with the first FROZEN item removed called: ";
    // Item::print4FirstItemVector(emptyList);
    // cout << endl;

    /*
     *
     * Testing Method: noDuplicates
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "List 1 no duplicates: ";
    // cout << (Item::noDuplicates(itemList1) ? "true" : "false") << endl;
    // cout << "List 2 no duplicates: ";
    // cout << (Item::noDuplicates(itemList2) ? "true" : "false") << endl;
    // cout << "List 3 no duplicates: ";
    // cout << (Item::noDuplicates(itemList3) ? "true" : "false") << endl;
    // cout << "List 4 no duplicates: ";
    // cout << (Item::noDuplicates(itemList4) ? "true" : "false") << endl;
    // cout << "List 5 no duplicates: ";
    // cout << (Item::noDuplicates(itemList5) ? "true" : "false") << endl;
    // cout << "Empty List no duplicates: ";
    // cout << (Item::noDuplicates(emptyList) ? "true" : "false") << endl;
    // cout << endl;

    /*
     *
     * Testing Method: isItemPerTypeOriginBudget
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "Exercise #8" << endl;
    // cout << "List 1 items available per parameters: ";
    // cout << (Item::isItemPerTypeOriginBudget(FROZEN,"USA",4.58,itemList1) ? "true" : "false") << endl;
    // cout << "List 2 items available per parameters: ";
    // cout << (Item::isItemPerTypeOriginBudget(DAIRY,"Italia",9.58,itemList2) ? "true" : "false") << endl;
    // cout << "List 3 items available per parameters: ";
    // cout << (Item::isItemPerTypeOriginBudget(DAIRY,"Greece",20.05,itemList3) ? "true" : "false") << endl;
    // cout << "List 4 items available per parameters: ";
    // cout << (Item::isItemPerTypeOriginBudget(FRESH,"USA",6.98,itemList4) ? "true" : "false") << endl; 
    // cout << "List 5 items available per parameters: ";
    // cout << (Item::isItemPerTypeOriginBudget(SNACK,"USA",4.88,itemList5) ? "true" : "false") << endl; 
    // cout << "Empty List items available per parameters: ";
    // cout << (Item::isItemPerTypeOriginBudget(FROZEN,"USA",4.58,emptyList) ? "true" : "false") << endl; 
    // cout << endl;

    /*
     *
     * Testing Method: mostExpensiveType
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "Most Expensive Type List 1: ";
    // cout << Item::enumToString(Item::mostExpensiveType(itemList1)) << endl;
    // cout << "Most Expensive Type List 2: ";
    // cout << Item::enumToString(Item::mostExpensiveType(itemList2)) << endl;
    // cout << "Most Expensive Type List 3: ";
    // cout << Item::enumToString(Item::mostExpensiveType(itemList3)) << endl;
    // cout << "Most Expensive Type List 4: ";
    // cout << Item::enumToString(Item::mostExpensiveType(itemList4)) << endl; 
    // cout << "Most Expensive Type List 5: ";
    // cout << Item::enumToString(Item::mostExpensiveType(itemList5)) << endl; 
    // cout << "Most Expensive Type Empty List: ";
    // cout << Item::enumToString(Item::mostExpensiveType(emptyList)) << endl; 
    // cout << endl;

    /*
     *
     * Testing Method: listItemPerType
     *
     */
    
    // emptyList = {};
    // itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    // itemList2 = {i1, i4, i5, i6, i7, i10};
    // itemList3 = {i3, i4, i8, i9, i10};
    // itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    // itemList5 = {i1, i9, i10};

    // cout << "Exercise #10" << endl;
    // cout << "SWEET List from List 1: " + Item::listItemPerType(SWEET, itemList1) << endl;
    // cout << "FRESH List from List 1: " + Item::listItemPerType(FRESH, itemList1) << endl;
    // cout << "SNACK List from List 1: " + Item::listItemPerType(SNACK, itemList1) << endl;
    // cout << "BAKED List from List 1: " + Item::listItemPerType(BAKED, itemList1) << endl; 
    // cout << "FROZEN List from List 1: " + Item::listItemPerType(FROZEN, itemList1) << endl;
    // cout << "DAIRY List from List 1: " + Item::listItemPerType(DAIRY, itemList1) << endl;
    // cout << endl;

    /*
     *
     * Testing Method: difference
     *
     */
    
    emptyList = {};
    itemList1 = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};
    itemList2 = {i1, i4, i5, i6, i7, i10};
    itemList3 = {i3, i4, i8, i9, i10};
    itemList4 = {i1, i2, i3, i4, i7, i7, i9};
    itemList5 = {i1, i9, i10};

    cout << "Difference of list 1 and list 1: ";
    Item::print4FirstItemVector(Item::difference(itemList1,itemList1));
    cout << "Difference of list 1 and list 2: ";
    Item::print4FirstItemVector(Item::difference(itemList1,itemList2));
    cout << "Difference of list 2 and list 1: ";
    Item::print4FirstItemVector(Item::difference(itemList2,itemList1));
    cout << "Difference of list 2 and empty list: ";
    Item::print4FirstItemVector(Item::difference(itemList2,emptyList));
    cout << "Difference of list empty list and 2: ";
    Item::print4FirstItemVector(Item::difference(emptyList,itemList2)); 
    cout << endl;
}

/*
 * METHOD: priceOfList
 * Return the sum of all the prices of the items in the item list.
 */
double Item::priceOfList(vector<Item> itemList){
    // YOUR CODE HERE
    double cost;
    if(itemList.size() == 0) {
        return 0;
    }
    for(int i = 0; i < itemList.size(); i++) {
        cost = cost + itemList[i].getPrice();
    }
    return cost; //Dummy Return
}

/*
 * METHOD: originCount
 * Return the count of items in list for a given origin.
 */
int Item::originCount(string origin, vector<Item> itemList){
    // YOUR CODE HERE
    int count = 0;
    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getOrigin() == origin) {
            count = count + 1;
        }
    }
    return count; //Dummy Return
}

/*
 * METHOD: getTypeList
 * Return a new vector that contains all the items that have the given 
 * type.
 */
vector<Item> Item::getTypeList(PType type, vector<Item> itemList){
    // YOUR CODE HERE
    vector<Item> result;

    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getType() == type) {
            result.push_back(itemList[i]);
        }
    }

    return result; //Dummy Return
}

/*
 * METHOD: firstItemOccurrence
 * Return the first item that has a a lower or equal price than the given price.
 * If there is no item return and new item with the following attributes:
 * Name = No item
 * Origin = N/A
 * Price = 0
 * Type = OTHER
 */
Item Item::firstItemOccurrence(double price, vector<Item> itemList){
    // YOUR CODE HERE
    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getPrice() < price) {
            return itemList[i];
        }
    }
    return Item("No item", "N/A", 0.0, OTHER);//Dummy Return
}

/*
 * METHOD: mostExpensiveItemPerType
 * Return the most expensive item price in the list of a given type.
 * If the list doesn't have that given type return -1.0.
 */
double Item::mostExpensiveItemPerType(PType type, vector<Item> itemList){
    // YOUR CODE HERE
    int counter = 0;
    double price = 0;
    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getType() == type && itemList[i].getPrice() > price) {
            price = itemList[i].getPrice();
            counter++;
        }
    }
    if(counter > 0) {
        return price;
    } else {
        return -1.0;//Dummy Return
    }
}

/*
 * METHOD: removeItemWithType
 * Remove the first occurence of an item of the given type.
 * If there is no item with the given type leave the list unchanged.
 */
void Item::removeItemWithType(PType type, vector<Item> &itemList){
    // YOUR CODE HERE
    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getType() == type) {
            itemList.erase(itemList.begin() + i);
            break;
        }
    }
}

/*
 * METHOD: noDuplicates
 * Return FALSE if there is any duplicate items on the given list.
 * Otherwise return TRUE.
 * Hint: Use the equals instance method provided.
 *
 */
bool Item::noDuplicates(vector<Item> itemList){
    // YOUR CODE HERE
    for(int i = 0; i < itemList.size(); i++){
        for(int j = i+1; j < itemList.size(); j++) {
            if(itemList[i].equals(itemList[j])) {
                return false;
            }
        }
    }
    return true; //Dummy Return
}

/*
 * METHOD: isItemPerTypeOriginBudget
 * Return true if there is at least one item in the given list that comes 
 * from the given origin, is of the given type and its price is less or equal 
 * than the given budget. Otherwise return false.
 */
bool Item::isItemPerTypeOriginBudget(PType type, string origin, double budget, vector<Item> itemList){
    // YOUR CODE HERE
    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getType() == type && itemList[i].getOrigin() == origin && itemList[i].getPrice() <= budget) {
            return true;
        }
    }
    return false; //Dummy Return
}

/*
 * METHOD: mostExpensiveType
 * Return the type of most expensive item in the given list.
 * If the list is empty return OTHER type.
 */
PType Item::mostExpensiveType(vector<Item> itemList){
    // YOUR CODE HERE
    if(itemList.size() == 0) {
        return OTHER;
    }
    Item expensive;
    double price = 0;
    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getPrice() > price) {
            price = itemList[i].getPrice();
            expensive = itemList[i];
        }
    }
    return expensive.getType(); //Dummy Return
}

/*
 * METHOD: listItemPerType
 * Return a string that contains a comma-separated list of the names
 * of all the items of the given type.
 * 
 * Hint: Look at the test cases to see the formatting of the resulting
 * string.
 */
string Item::listItemPerType(PType type, vector<Item> itemList){
    // YOUR CODE HERE
    string result = "";
    int counter = 0;
    for(int i = 0; i < itemList.size(); i++) {
        if(itemList[i].getType() == type && counter == 0) {
            result += itemList[i].getName();
            counter++;
        } else if(itemList[i].getType() == type && counter != 0) {
            result +=  ", " + itemList[i].getName();
        }
    }
    return result; //Dummy Return
}

/*
 * METHOD: difference
 * Returns a new vector containing the DIFFERENCE of all the Items
 * from the two parameter vectors (v1 - v2), that is the set of the items on parameter 
 * v1 that are NOT present on parameter v2.
 * Use the given equals method to determine if two items are the same.
 */
vector<Item> Item::difference(vector<Item> v1, vector<Item> v2){
    // YOUR CODE HERE
    vector<Item> result;
    for(int i = 0; i < v1.size(); i++) {
        bool match = false;
        for(int j = 0; j < v2.size(); j++) {
            if(v1[i].equals(v2[j])) {
                match = true;
            }
        }
        if(match == false) {
            result.push_back(v1[i]);
        }
        match = false;
    }
    return result; //Dummy Return
}


  
