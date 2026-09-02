#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Declare a Map
    map<int, int>map1;
    map<int, string>map2;
    map<int, string>map3 = {{10, "abc"},{20, "def"},{30, "bbb"}};

    //Insert values in a map
    map1[1] = 2;
    map1[5] = 4;
    map1[3] = 3;
    map1[4] = 6;
    map1.insert({2, 10});

    //Modify value
    map1[3] = 7;
    map1.insert({2, 11});
    map1.at(4) = 8; //Throws out of range if key is not present in the map

    //Capacity of a map
    cout << "Is the map empty? " << map1.empty() << endl; //returns a flag to check if the map is empty or not
    cout << "Size of map1 = " << map1.size() << endl;
    cout << "Size of map2 = " << map2.size() << endl;
    cout << "Maximum size of the map = " << map1.max_size() << endl;


    //Insert values in map 2
    map2.insert({10, "abc"});
    map2.insert({20, "def"});

    //Declare Iterators
    map<int, int>::iterator it;
    cout << "Printing Map1 with iterator: " << endl;
    for(it = map1.begin(); it!= map1.end(); it++)
    {
        cout << it->first << "   " << (*it).second << endl;
    }
    cout << endl;
    cout << "Printing Map2 with iterator: " << endl;
    for(auto itr = map2.begin(); itr!= map2.end(); itr++){
        cout << itr->first << " " << (*itr).second << endl;
    }
    cout << endl;

    //Use for each loop
    //here m is a reference, not a copy
    cout << "Using for each loop to print Map2:" << endl;
    for(auto& m: map2){
        cout << m.first << endl;
    }

    //Suppose we want to print the elements backwards
    map<int, int>::reverse_iterator rit;
    cout << "Printing Map1 in reverse: " << endl;
    for(rit = map1.rbegin(); rit!= map1.rend(); rit++){
        cout << rit->first << "   " << (*rit).second << endl;
    }
    //Difference between begin and cbegin
    auto it_begin = map2.begin();
    cout << it_begin->second << endl;
    it_begin->second = "AAA";
    cout << it_begin->second;

    auto it_cbegin = map2.cbegin();
    //it_cbegin->second = "aaa"; //will throw an error as the iterator is constant

    //Functions
    map<int, string> b1,b2;
    b1[8]= "X";
    b1[7]= "Y";
    b2[5]= "M";
    b2[6]= "N";
    b2[8] = "O";
    b1.swap(b2);
    map<int, string>::iterator it_swap;
    for(it_swap = b1.begin(); it_swap!= b1.end(); it_swap++){
        cout << it_swap->first << "   " << it_swap->second << endl;
    }
    b1.clear(); //clearing b1
    cout << "Size of b1 becomes = " << b1.size() << endl;

    //Find and Erase
    auto it2 = b2.find(8); //we need to give the key here
    if(it2 == b2.end()){
        cout << "Value not found" << endl;
    }
    else{
        cout << "Value = " << it2->second << endl;
    }
    if(it2 == b2.end()){
        cout << "Value can not be erased" << endl;
    }
    else{
        b2.erase(it2);
    }
    b2.erase(prev(b2.end())); //remove the last element of the b2 map

    for(auto it = b2.begin(); it!= b2.end(); it++){
        cout << it->first << "   " << (*it).second << endl;
    }
    //count function
    cout << "Is 4 in map1? = " << map1.count(4) << endl;

    //Multimap allows multiple elements with same key
    multimap<int, string> myMap;
    myMap.insert({4, "apple"});
    myMap.insert({2, "banana"});
    myMap.insert({3, "cherry"});
    myMap.insert({3, "citrus"});
    myMap.insert({5, "date"});
    int key = 3;
    auto range = myMap.equal_range(key);
    // Print the elements in the range
    cout << "Elements with key " << key << " are:" << endl;
    for (auto it = range.first; it != range.second; ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

  map<char,int> mymap;
  map<char,int>::iterator itlow,itup;
  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  itlow=mymap.lower_bound ('b');
  itup=mymap.upper_bound ('d');

  mymap.erase(itlow,itup);
  for(auto it=mymap.begin(); it!=mymap.end(); ++it){
    cout << it->first << " => " << it->second << '\n';
  }

  //REVIEW UNORDERED_MAP TOO, ALSO TRY TO FIGURE OUT THE DIFFERENCE BETWEEN MAP AND UNORDERED_MAP
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    //Declare and Initialize a Pair
    pair<int, string>pair1;
    pair1 = make_pair(20, "A");
    pair<int, string>pair2(10, "B");
    pair<int, string>pair3 = {30, "C"};

    //suppose we haven't initialized a pair
    pair<int, string>p;
    cout << "Before Initialization = " << p.first << "\t" << p.second << endl; //default initialization, first element is int, so 0, second = ""
    p.first = 10;
    p.second  = "X";
    cout << "After Initialization = " << p.first << "\t" << p.second << endl; //default initialization, first element is int, so 0, second = ""
    //Access Elements
    //we need to access members of pairs using first and second
    cout << "First element = " << pair1.first << " Second Pair = " << pair1.second << endl;

    //Compare between pairs
    //First compares between the first element of each pairs, if one is greater than other then result is based on that
    //initially pair1.first = 20, pair2.first = 10, so pair1 is greater
    if(pair1 > pair2)
    {
        cout << "Pair1 is greater than pair2" << endl;
    }
    else
    {
        cout << "Pair2 is greater than pair1" << endl;

    }
    //Now if first element of both pairs are equal, the result is shown after comparision of second elements of the pairs
    pair1.first = 10;
    pair2.first = 10;
    //2nd element of pair1 = A, 2nd element of pair2 = B
    if(pair1 > pair2)
    {
        cout << "Pair1 is greater than pair2" << endl;
    }
    else
    {
        cout << "Pair2 is greater than pair1" << endl;

    }
    //----Create a vector of pairs and sort them-----------
    vector<pair<int, string>>pair_vector = {pair1, pair2, pair3};
    sort(pair_vector.begin(), pair_vector.end()); //same as compare
    for (auto p : pair_vector)
    {
        cout << p.first << " " << p.second << endl;
    }

    //Nested Pairs
    pair<pair<int, string>, int> nested_pair = make_pair(make_pair(1, "ABC"), 20);
    cout << nested_pair.first.first << "\t";
    cout << nested_pair.first.second << "\t";
    cout << nested_pair.second << endl;

    vector<vector<int>>matrix = {{1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    pair< vector<vector<int>>,int> my_pair = make_pair(matrix, 1000);
    cout << "Second element: " << my_pair.second << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << my_pair.first[i][j] << " ";
        }
        cout << endl;
    }
    pair< pair< vector<vector<int> >, int>, string> my_new_pair = make_pair(make_pair(matrix, 1000), "AUST");
    cout << "Second element: " << my_new_pair.second << endl;
    cout << "Second element: " << my_new_pair.first.second << endl;
    for(int i = 0 ; i < 3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << my_new_pair.first.first[i][j] << " ";
        }
        cout << endl;
    }
    vector< pair< pair< vector<vector<int> >, int>, string> > v;
    v.push_back( make_pair(make_pair(matrix, 5000), "AUST") );
    v.push_back( make_pair(make_pair(matrix, 6000), "AUST") );
    cout << v[1].first.second;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    //-----------Declaring a 1D Vector--------------
    //vector<datatype> name;
    //vector<datatype>name(size);
    vector<string>s1;

    //------------Initializing a Vector--------------
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2{6,7,8,9};
    vector<int> v3(5,5); // Declaring 5 elements which are initialized to 5
    s1.assign(4, "Algo"); //The same thing can be achieved by using the assign function to initialize all 4 elements with ALgo

    //-----------Insert elements to vector-----------
    //after inserting an element to a vector, size will be dynamically updated
    v1.push_back(6);    //6 will be inserted at the the end of vector v1
    //input: 1 2 3 4 5
    //output:1 2 3 4 5 6

    //we can also specify a specific position to insert the element
    //suppose we want to insert a element at the first position
    //v1.insert(0, 5); this line will give an error, since we can not directly use the index number in insert function
    //we need to use the iterator
    //In the above example, an element is inserted at the end of the vector, which can also be achieved by
    v1.insert(v1.end(), 10);
    //input: 1 2 3 4 5 6
    //output:1 2 3 4 5 6 10
    v1.insert(v1.begin(), 7); // the first parameter specifies the iterator, 2nd parameter specifies the value
    //input: 1 2 3 4 5 6 10
    //output:7 1 2 3 4 5 6 10
    //now if we want to insert an element at the 3rd position, we can simply add +2 from the iterator of the first element
    //which is pointed by begin()
    v1.insert(v1.begin()+2, 11);
    //input: 7 1 2 3 4 5 6 10
    //output: 7 1 11 2 3 4 5 6 10
    cout << *v1.begin() << endl; // we are printing the value pointed by the iterator of begin, so first element is printed

    //we can also insert multiple values using insert function
    v1.insert(v1.begin(),3, 5); //here three 5s are inserted from the iterator of first element
    //so output will be like this:5 5 5 ......(rest of the vector)

    //if we want to insert a range of elements, we first need to specify the position, then the range of the elements
    v3.insert(v3.begin()+3, v2.begin(), v2.end()); //from 4th position, v3 vector will be inserted
    //so output: 5 5 5 (6 7 8 9) 5 5
    //suppose, we want to insert just the middle 2 elements, we need to specify the range
    v3.insert(v3.begin()+3, v2.begin()+1, v2.end()-1);
    //so output:5 5 5 (7 8) 6 7 8 9 5 5

    //we want to replace the content of a vector with another vector
    vector<int>num1 = {1,2,3};
    vector<int>num2 = {4,5,6,7};
    num2.assign(num1.begin(),num1.end());
    //num2 is now assigned with the elements of num1,num1 has 3 elements, 1,2,3
    //num2's size will also be dynamically adjusted to the size of num1 and will discard the previous elements
    cout << "Size of num2 now becomes: " << num2.size() << endl;
    //original num2: {4, 5, 6, 7}, size = 4
    //after using the assign function:{1, 2, 3}, size = 3

    //FROM THE ABOVE EXAMPLES, THINK ABOUT THE DIFFERENCES BETWEEN INSERT AND ASSIGN IN VECTOR

    s1.resize(6, "A"); //here s1 will be resized to 6 and rest of the elements will be initialized with a

    //------------Printing a Vector-----------------
    //we can print vector like an array
    cout << "Value of v1 = ";
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] <<  " ";
    }
    cout << endl;
    //we can also use a for each loop/ranged loop
    //here each element of vector is directly copied
    cout << "Value of v2 = ";
    for(auto i: v2)
    {
        cout << i << " ";
    }
    cout << endl;
    //this is also a for each loop/ranged loop
    //but here each elements of the vector is referenced instead of copied
    cout << "Value of v3 = ";
    for(int& i: v3)
    {
        cout << i <<  " ";
    }
    cout << endl;
    //we are just reading the value, so no modification is needed here
    //so it's a good practice to use const when we are not modifying the elements
    cout << "Value of v3 = ";
    for(const int& i: v3)
    {
        cout << i << " ";
    }
    cout << endl;
    //using an iterator
    vector<int>::iterator it;
    cout << "Value of v1 = ";
    for(it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    //instead of declaring the it, we can also use auto
    cout << "Value of v4 = ";
    for(auto it = s1.begin(); it!= s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    //------------Accessing an element from Vector-----------
    cout << v3[2] << endl; //3rd element is accessed
    cout << v3.at(2) << endl;
    //now, suppose we want to access an out of bound element
    //v1 now has a size of 12, I want to access the 13th element
    cout << v1[12] << endl;       //will print 0
    //cout << v1.at(12) << endl; // will throw an out of range exception

    //Directly printing the first and last element
    cout << "First element of v2 = " << v2.front() << " ";
    cout << "Last element of v2 = " << v1.back() << endl;

    //-----------Size and Capacity--------------------
    vector<int>vec;
    cout << "Initial size = " << vec.size() << " " << "Capacity = " << vec.capacity() << endl;
    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        cout << "Size = " << vec.size() << " " << "Capacity = " << vec.capacity() << endl;
    }
    /*Output:
    Initial size = 0 Capacity = 0
    Size = 1 Capacity = 1
    Size = 2 Capacity = 2
    Size = 3 Capacity = 4
    Size = 4 Capacity = 4
    Size = 5 Capacity = 8
    Size = 6 Capacity = 8
    Size = 7 Capacity = 8
    Size = 8 Capacity = 8
    Size = 9 Capacity = 16
    Size = 10 Capacity = 16
    When the 1st element is inserted, the capacity becomes 1.
    When the 2nd element is inserted, the capacity doubles to 2.
    When the 3rd element is inserted, the capacity is not sufficient, so it doubles again (2 * 2 = 4).
    When the 4th element is inserted, the capacity remains 4 since there is enough space.
    However, when the 5th element is inserted, the capacity doubles to 8.
    The capacity does not double again until the size reaches 9.
    So, we can see capacity does not increase with every insertion but only when they need more space
    Capacity is  always greater than or equal to the size
    */

    vector<int>cap; //here we have reserved a capacity of 100
    cap.reserve(8);
    cout << "Initial size = " << cap.size() << " " << "Capacity = " << cap.capacity() << endl;
    for(int i = 0; i < 10; i++)
    {
        cap.push_back(i);
        cout << "Size = " << cap.size() << " " << "Capacity = " << cap.capacity() << endl;
    }
    //Once it reaches size 9, it will double down. But from size 0 to 8, it will have the reserved capacity of 8
    //we can also use shrink_to_fit to make the capacity similar to the size, for example:
    vector<int>vec3;
    vec3.reserve(100);
    for(int i = 0; i < 5; i++)
    {
        vec3.push_back(i);
    }
    cout << endl << "Size = " << vec3.size() << " ," << "Capacity = " << vec3.capacity();
    vec3.shrink_to_fit();
    cout << "\tAfter using shrink to fit function: " << "Size = " << vec3.size() << " ," << "Capacity = " << vec3.capacity() << endl;

    //--------Remove an element from a vector------------
    //Push back inserts and element at the end of the vector, pop back removes the last element of the vector
    vec.pop_back();
    //the last element of vec = 9, it will be removed and hence the output will be: 0 1 2 3 4 5 6 7 8
    //now if we want to remove element from a specific position of the vector, we need to use the erase function
    vec.erase(vec.begin()+2); //it will remove the 3rd element, output: 0 1 3 4 5 6 7 8
    //we need to use the iterator to specify the position of the element
    //vec.erase(vec.front()); this will not work as vec.front() is specifying the first element instead of the iterator pointing to the first element

    //We can also use the erase function to erase a range of elements
    //In that case, we need to write it in this way: vec.erase(start, end),
    //All elements from start(inclusive) to end(exclusive) will be erased
    cout << endl;
    vec.erase(vec.begin()+2, vec.begin()+ 5); //will erase 3rd to 5th  (indices 2nd to 4th)
    //here we are adding +5 which means 6th element, but for erase function, end position is exclusive, so it will erase till 5th element
    //Input: 0 1 3 4 5 6 7 8 Output: 0 1 6 7 8
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    //---------Clear and Empty functions------------
    s1.clear();
    cout << "Is s1 empty? = " << s1.empty() << endl; //since s1 has been cleared, s1 is empty, so it will print 1

    //---------Swap-----------------
    vector<float>swap1 = {1.2, 2.3, 4.1, 7.8};
    vector<float>swap2 = {2.5, 4.6, 6.7};
    swap(swap1, swap2);
    cout << "Swap1 becomes: " << endl;
    for(int i = 0; i < swap1.size(); i++)
    {
        cout << swap1[i] << "\t";
    }
    cout << endl;
    cout << "Swap2 becomes: " << endl;
    for(int i = 0; i < swap2.size(); i++)
    {
        cout << swap2[i] << "\t";
    }
    cout << endl;
    //now swap1: {2.5, 4.6, 6.7}
    //swap2: {1.2, 2.3, 4.1, 7.8}

    cout << "Swapping a range of values: " << endl;
    //Swapping a range of values swap_ranges(start1, end1, start2) //
    //start1, end1:the range whose elements will swapped, where start1 is inclusive and end1 is exclusive
    swap_ranges(swap1.begin()+1, swap1.begin()+ 3, swap2.begin() + 3); //we are trying to swap the 2nd and 3rd elements of
    //swap1 with swap2, since the end position is exclusive we are pointing to 4th index, so that it erases till 3rd index
    for(int i = 0; i < swap2.size(); i++)
    {
        cout << swap2[i] << "\t";
    }
    //NOW TRY TO SWAP ELEMENTS WITHIN THE SAME VECTOR

    //---------SOME COMMON FUNCTIONS----------------
    vector<int>vector1 = {1,5,2,4,6};
    reverse(vector1.begin(), vector1.begin() + 3);  //it will reverse 0th index to 2nd index
    //so output will be: 2 5 1 4 6
    //if we want to reverse the whole vector, we can simply use vector.end() in the end parameter
    cout << "After performing reverse, the output will be:" << endl;
    for(int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;
    sort(vector1.begin(), vector1.end()); // will sort the given position in descending order
    for(int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;
    //now suppose we want to sort the vector in ascending order
    sort(vector1.begin(), vector1.end(), compare);
    for(int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;

    //Find an element
    int element_value = 4;
    auto it2 = find(vector1.begin(), vector1.end(), element_value);
    if(it2 == vector1.end())
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index " << it2 - vector1.begin() << endl; //we can also use distance(vector1.begin(), it2) which will produce the same result
    }
    //Updating an element
    vector1[2] = 9;
    vector1.at(3) = 8;
    for(int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;

    //Declaring a 2D Vector and initializing it with user input
    vector<vector<int>>vec_2d;
    cout << "Enter the number of rows and columns = ";
    int n, m;
    cin >> n >> m;
    cout << endl;
    vec_2d.assign(n, vector<int>(m, 0)); //n rows, each with m columns initialized to 0
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> vec_2d[i][j];
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout <<  vec_2d[i][j] << " ";
        }
        cout << endl;
    }
    //TRY TO SORT A 2D VECTOR, FIRSTLY ROW WISE, THEN COLUMN WISE, THEN ENTIRELY

}

//643

#include <bits/stdc++.h>
using namespace std;

bool isPrefix(string root, string word)
{
    if (root.length() > word.length())
        return false;

    for (int i = 0; i < root.length(); i++)
    {
        if (root[i] != word[i])
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    string dictionary[n];

    for (int i = 0; i < n; i++)
    {
        cin >> dictionary[i];
    }

    cin.ignore();

    string sentence;
    getline(cin, sentence);

    string word = "";
    bool first = true;

    for (int i = 0; i <= sentence.length(); i++)
    {
        if (i == sentence.length() || sentence[i] == ' ')
        {
            string ans = word;

            for (int j = 0; j < n; j++)
            {
                if (isPrefix(dictionary[j], word))
                {
                    if (ans == word || dictionary[j].length() < ans.length())
                    {
                        ans = dictionary[j];
                    }
                }
            }

            if (!first)
                cout << " ";

            cout << ans;

            first = false;
            word = "";
        }
        else
        {
            word += sentence[i];
        }
    }

    return 0;
}
