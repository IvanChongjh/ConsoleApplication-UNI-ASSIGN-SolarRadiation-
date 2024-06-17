/****
@author Ivan Chong Jia Hao
@since 29/5/2023
@version 1.01
*/
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
/**
Constant Variable Declaration of Default Size
*/
const int INITAL_SIZE = 8; // default capacity size

/**
Template Class of T variable Specified by User;
*/
template <class T>
class Vector
{
    /**
    Private Declared Variables
    */
private :
    T*m_array;  // pointer to array
    int m_numElements; // number of elements in the array
    int m_capacity; // size of actual array

public :
    /**
    Default Constructor
    */
    Vector(); // constructor
    /**
    Destructor
    */
    ~Vector(); // destructor
    /**
    constructor overloading
    @param int n, n number of element
    */
    Vector(int n); // constructor to initialize size
    /**
    constructor overloading
    @param T object, pass in object to copy capacity,size
    */
    Vector(T&AnotherVec);// copy constructor assignment;
    /**
    Operator assignment "=".
    @param assigns object with another object, copy contents , element size ,capacity
    */
    T& operator = (const T&AnotherVec); // assignment operator - deep copying
    /**
    operator calling by index example vector[0] where index 0 is param pass into, returns index in dynamic array
    @param pass by reference & index number to return
    @return T object
    */
    T& operator [] (const int& index); // operator defining [0] returns value at array at 0 location
    /**
    add element into array
    @param T element, value that is added into dynamic array;
    @return bool
    */
    bool add(const T &element); // push_back or add element in vector also auto increases if capacity is met
    /**
    Reset vector to default vector, Deleting Elements and resizes to default
    */
    void remove(); // deletes everything in vector;
    /**
    InsertAt() performs a insert value at specified index by user, pushing the index above it by 1
    @param Index of array
    @param Element user wish to add
    @return void
    */
    void InsertAt(const int &index, const T&element); // insertAt() adds new element in specified index and extends array size
    /**
    Deletes from specified indexes from index one to index 2 and resizes
    @param int indexOne
    @param int indexTwo
    @return void
    */
    void deletefrom(const int &indexOne,const int &indexTwo); // deletes from first index to second index;
    /**
    Assessor for size of elements in dynamic array
    @return void
    */
    int size(); // return size of dynamic size
    /**
    assessor for capacity of capacity
    @return void
    */
    int capacity(); // return capacity of dynamic array
    /**
    call out index and return value
    @param int index
    @return T element
    */
    T& at(const int& index);//at() // equivalent to [] cout << vec[5]  at() checks if index entered is within range
    /**
    Checks if vector is empty
    @return bool
    */
    bool empty(); // checks if the vector is empty return true if size is 0 , false otherwise.
    /**
    modifys the value at index with new value;
    @param int index
    @param T mod
    */
    void modifyAt(const int& index, const T& mod); //vec[5]= "abc";


};
template <class T> // copying constructor
Vector<T> :: Vector(T&AnotherVec) // Vector template method that pass in (T)Vect to copy
{
    m_capacity = AnotherVec.capacity(); // m_cap copy another vec capacity
    m_numElements = AnotherVec.size(); // num elements in vect copy vect size of element
    for (int i = 0 ; i < m_numElements; i ++ ) // loops through to copy index by index in dynamic array
    {
        m_array[i] = AnotherVec[i];
    }
}

template <class T> // assignment operator (deep copying)
T& Vector <T> :: operator=(const T&AnotherVec) // operator  " = " , perform deep copying by using heap array

{

    m_numElements = AnotherVec.size(); // copy elements
    m_capacity = AnotherVec.capacity(); // copy capacity
    T*temparray = new T[m_capacity]; // creates temp array
    for(int i = 0 ; i < m_numElements; i ++) // for loop to loop T values into another vect by index
    {
        temparray[i] = AnotherVec[i]; // assign

    }
    delete []m_array;  // delete vect dynamic array contents
    m_array = temparray; // assign vect to temp vect
    delete []temparray; // delete temp array
    temparray = nullptr; // set temp array address to null

}
template <class T>
Vector <T> :: Vector(int n) // vect assign with size of n for element size
    :m_numElements(0),m_capacity(0),m_array(new T[INITAL_SIZE])
{
    m_numElements = n;  // n parameter pass to m_num private declared variable
    if (n > INITAL_SIZE) // checks if n assigned by user is more than initial size of 10
        m_capacity = n*2; // if assigned value is more than 10, default capacity x 2
    else
        m_capacity = INITAL_SIZE; // if assigned value is lower than default cap of 10, assign without x2

}
template <class T>
Vector<T> :: Vector()
    :m_numElements(0),m_capacity(0),m_array(new T[INITAL_SIZE]) // default constructor initialized by member initialized method
{

//    m_numElements = 0; // default initializer
//    m_capacity = 0; // default initializer
//    m_array = new T[INITAL_SIZE]; // creates dynamic array using m_array pointer in heap memory
    if(m_array!= nullptr) // check if array is created by checking the address if address is not null
    {
        m_capacity = INITAL_SIZE; // default initializer with initial capacity of 8 declared
    }

}

template <class T>
Vector<T> :: ~Vector() //  when program closes the destructor will destroy heap memory arrays
{
    if(m_array != nullptr) // checks if dynamic array is null if it is not null
    {
        delete []m_array;// / proceeds to delete array and set to null;
        m_array = nullptr;
    }
}

template <class T>
bool Vector <T> :: add(const T &element) // add element feature just like pushback if dynamic array size elements reacher capacity
{
    if(m_numElements >= m_capacity) // if the elements is equals or more than capacity
    {
        int newCapacity = m_capacity * 2;  // increase capacity by 2x
        T*tempArray = new T[newCapacity];  // creates a dynamic temp array with new capacity
        // if tempArray is successfully allocated
        // copy all element from old array to new array;
        if( tempArray != nullptr) // checks if capacity is empty
        {
            for(int i = 0 ; i < m_numElements ; i ++) // using loop to copy elements in m_array to temp array
            {

                tempArray[i] = m_array[i]; // copy m_array element into temp array element
            }
            delete []m_array; // after completion delete m_array
            m_array = tempArray; // using temp array with updated capacity to copy to m_array
            tempArray = nullptr; // set temparray to null
            m_capacity = newCapacity; // update capacity value
            m_array[m_numElements++] = element; // increment elements by 1 to input new element
            delete []tempArray; // deletes temp array
            return true; // return bool true // successful completion symbolize completion
        }
        else
        {
            return false; // if temp is not empty then return false fail to attempt to add element
        }
    }
    else // if capacity is not met then just add element
    {
        // add new item into array
        m_array[m_numElements++] = element; // m_array index increases by 1 and load in element
        return true;
    }

}
template <class T>
T& Vector<T> :: operator [] (const int& index) // operator overloading
{
    if( index >= 0  && index < m_capacity)// checks if user input is within range
    {
        return m_array[index]; // return values specified by user in array
    }
    else
        throw " Index Out Of Range "; // throw error if input by user is out of range
}

template <class T>
int Vector <T>:: size()
{
    return m_numElements; // assessor to return value of m_numElements
}
template <class T>
void Vector<T> :: InsertAt(const int &index,const T &element) // user enters index num and new value
{

    if(index  >= 0  && index < m_numElements) // checks if user entered within range of elements
    {

        if(m_numElements == m_capacity) // if elements in range of capacity set ( resizes )
        {
            m_capacity *= 2;
        }
        for(int i= m_numElements; i >= index; i--) // if user adds push all values above by to create space
        {
            m_array[i+1] = m_array[i];

        }
        m_array[index] = element; // add element in specified location
        m_numElements++;

    }
    else
    {
        throw "Index Out Of Range"; // throw error if user input index not within range
    }

}

template <class T>
int Vector<T> :: capacity() // assessor to check the capacity of array
{
    return m_capacity;
}
template < class T>
bool Vector<T> :: empty() // checks if vector is empty
{
    if(m_numElements == 0)
        return true;
    else
        return false;
}
template <class T>
T& Vector<T> :: at(const int &index) // returns value at location specified by user
{
    if(index  >= 0  && index < m_numElements)
    {
        return  m_array[index];
    }
    else
    {
        throw " Out Of Range ";
    }
}

template <class T>
void Vector<T> :: modifyAt(const int &index, const T& mod) // modify value at specific location
{
    int newcap = index * 2;
    if(index > m_numElements){
        m_numElements = index;
        m_array[index] = mod;
    }
    if (index > capacity())
    {
        m_capacity = newcap;
    }
}
template <class T>
void Vector <T> :: remove() // removes everything and reset vector
{
    delete[]m_array;
    m_numElements = 0;
    m_capacity = INITAL_SIZE;
}

template <class T>
void Vector <T> :: deletefrom( const int &indexOne, const int &indexTwo) // this will delete from first index to second index
{

    if (indexOne >= 0 && indexOne < m_numElements)
    {
        if (indexTwo >= indexOne && indexTwo < m_numElements)
        {

            int NewCountOfElement = 0;
            int upperindex = indexTwo;
            int lowerindex = indexOne;
            int numtomove = m_numElements - upperindex + lowerindex;

            T*tempArray = new T[m_capacity];


            for(int i = 0 ; i < lowerindex; i ++ )
            {
                tempArray[i] = m_array[i]; // this will input all elements before indexOne
                NewCountOfElement++;
            }

            for(int x = upperindex ; x < m_numElements ; x ++)
            {
                tempArray[lowerindex] = m_array[x];
                lowerindex++;
                NewCountOfElement++;
            }

            delete []m_array; // after completion delete m_array
            m_array = tempArray; // using temp array with updated capacity to copy to m_array
            delete []tempArray;
            tempArray = nullptr;
            m_capacity = NewCountOfElement*2;
            m_numElements = NewCountOfElement;
        }

    }
}
#endif // VECTOR_H_INCLUDED
