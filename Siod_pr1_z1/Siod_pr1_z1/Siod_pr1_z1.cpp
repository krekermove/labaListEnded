#include "InitClass.h"
#include "Functions.h"

int main() {
    List<DataType> myList;
    char menu;
    cout << "Enter file name:" << endl;
    cin >> myList.path;
    myList.read_file();
    do {
        system("CLS");
        cout << "1. Insert" << endl;
        cout << "2. Show" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Edit" << endl;
        cout << "6. Delete list" << endl;
        cout << "7. Exit" << endl;
        menu = getchar();
        switch (menu)
        {
        case '1': myList.push_back(myList.input_data()); break;
        case '2': myList.show(); break;
        case '3': myList.search(); break;
        case '4': myList.delete_node(); break;
        case '5': myList.edit(); break;
        case '6': myList.delete_list(); break;
        }
    } while (menu != '7');
    myList.fout.close();
    myList.fin.close();
    return 0;
}