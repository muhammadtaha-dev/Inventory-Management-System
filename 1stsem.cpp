#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Product
{
    int id;
    string name;
    string description;
    string category;
    int quantity;
    double price;
    int supplierID;
};

vector<Product> products;

int findProductbyID(int id)
{
    for(int i=0;i<products.size();i++)
    {
        if(products[i].id==id)
        {
            return i;
        }
    }
    return -1;
}

int findProductbyName(string name)
{
    for(int i=0;i<products.size();i++)
    {
        if(products[i].name==name)
        {
            return i;
        }
    }
    return -1;
}

void addproduct(int num)
{
    if(num==1)
    {
      Product newProduct;
      cout<<"Enter product ID: "<<endl;
      cin>>newProduct.id;
      cout<<"Enter product name: "<<endl;
      cin.ignore();
      getline(cin,newProduct.name);
      cout<<"Enter product description: "<<endl;
      cin>>newProduct.description;
      cout<<"Enter product category: "<<endl;
      cin>>newProduct.category;
      cout<<"Enter product quantity: "<<endl;
      cin>>newProduct.quantity;
      cout<<"Enter product price: "<<endl;
      cin>>newProduct.price;
      products.push_back(newProduct);
      cout<<"Product added successfully!"<<endl;
    }
    else if(num==2)
    {
        int means;
        cout<<"How you want to find the product (1 or 2)?"<<endl<<"1.By ID"<<endl<<"2.By name"<<endl;
        cin>>means;
        if(means==1)
        {
            int id;
            cout<<"Enter product ID: "<<endl;
            cin>>id;
            int index=findProductbyID(id);
            if(index!=-1)
            {
                int choice;
                cout<<"What you want to update (1-2)? "<<endl<<"1.Price"<<endl<<"2.Description"<<endl;
                cin>>choice;
                if(choice==1)
                {
                    double newprice;
                    cout<<"Current price of the product: "<<products[index].price<<endl;
                    cout<<"Enter the new price: "<<endl;
                    cin>>newprice;
                    products[index].price=newprice;
                }
                else if(choice==2)
                {
                    string newdescription;
                    cout<<"Current description of the product: "<<products[index].description<<endl;
                    cout<<"Enter the new description: "<<endl;
                    cin>>newdescription;
                    products[index].description=newdescription;
                }
                else
                {
                    cout<<"Invalid option!"<<endl;
                }
            }
            else
            {
                cout<<"Product not found!"<<endl;
            }    
        }
        else if(means==2)
        {
            string name;
            cout<<"Enter product name: "<<endl;
            cin.ignore();
            getline(cin,name);
            int index=findProductbyName(name);
            if(index!=-1)
            {
                int choice;
                cout<<"What you want to update (1-2)? "<<endl<<"1.Price"<<endl<<"2.Description"<<endl;
                cin>>choice;
                if(choice==1)
                {
                    double newprice;
                    cout<<"Current price of the product: "<<products[index].price<<endl;
                    cout<<"Enter the new price: "<<endl;
                    cin>>newprice;
                    products[index].price=newprice;
                }
                else if(choice==2)
                {
                    string newdescription;
                    cout<<"Current description of the product: "<<products[index].description<<endl;
                    cout<<"Enter the new description: "<<endl;
                    cin>>newdescription;
                    products[index].description=newdescription;
                }
                else
                {
                    cout<<"Invalid option!"<<endl;
                }
            }
            else
            {
                cout<<"Product not found!"<<endl;
            }    
        }    
    }
    else if(num==3)
    {
        int choice;
        cout<<"How you want to search the product (1-2): "<<endl<<"1.By ID"<<endl<<"2.By Name"<<endl;
        cin>>choice;

        if(choice==1)
        {
            int id;
            cout<<"Enter the ID of product: "<<endl;
            cin>>id;
            
            int index=findProductbyID(id);
            if(index!=-1)
            {
                cout<<"Product ID: "<<products[index].id<<endl;
                cout<<"Product name: "<<products[index].name<<endl;
                cout<<"Product Description: "<<products[index].description<<endl;
                cout<<"Product Price: "<<products[index].price<<endl;
                cout<<"Product Category: "<<products[index].category<<endl;
                cout<<"Product Quantity: "<<products[index].quantity<<endl;   
            }
            else
            {
                cout<<"Product not found!"<<endl;
            }
        }    
        else if(choice==2)
        {
            string name;
            cout<<"Enter the name of product: "<<endl;
            cin.ignore();
            getline(cin,name);

            int index=findProductbyName(name);
            if(index!=-1)
            {
                cout<<"Product ID: "<<products[index].id<<endl;
                cout<<"Product name: "<<products[index].name<<endl;
                cout<<"Product Description: "<<products[index].description<<endl;
                cout<<"Product Price: "<<products[index].price<<endl;
                cout<<"Product Category: "<<products[index].category<<endl;
                cout<<"Product Quantity: "<<products[index].quantity<<endl;
            }
            else
            {
                cout<<"Product not found!"<<endl;
            }
        }    

        else
        {
            cout<<"Invalid option!"<<endl;
        }
    }
    else if(num==4)
    {
        if(products.empty())
        {
            cout<<"No products available!"<<endl;
        }
        else
        {
            for(int i=0;i<products.size();i++)
            {
                cout<<"***** PRODUCT "<<i+1<<" *****"<<endl;
                cout<<"Product ID: "<<products[i].id<<endl;
                cout<<"Product name: "<<products[i].name<<endl;
                cout<<"Product Description: "<<products[i].description<<endl;
                cout<<"Product Price: "<<products[i].price<<endl;
                cout<<"Product Category: "<<products[i].category<<endl;
                cout<<"Product Quantity: "<<products[i].quantity<<endl;
            }
        }    
    }
    else if(num==5)
    {
        int min;
        cout<<"Enter your minimum threshold: "<<endl;
        cin>>min;
        bool found=false;
        for(int i=0;i<products.size();i++)
        {
            if(products[i].quantity<min)
            {
                cout<<"Product ID: "<<products[i].id<<endl;
                cout<<"Product name: "<<products[i].name<<endl;
                found=true;
            }
        }
        if(!found)
        {
            cout<<"No products below the threshold!"<<endl;
        }
    }
    else if(num==6)
    {
        int deleteChoice;
        cout<<"How you want to find the product to delete (1 or 2)?"<<endl;
        cout<<"1. By ID" << endl << "2. By Name" << endl;
        cin>>deleteChoice;
        
        if(deleteChoice == 1)
        {
            int deleteID;
            cout<<"Enter product ID to delete: ";
            cin>>deleteID;
            
            int index = findProductbyID(deleteID);
            if(index != -1)
            {
                cout<<"Found product: " << products[index].name << endl;
                cout<<"Are you sure you want to delete this product? (Y/N): ";
                char confirm;
                cin>>confirm;
                
                if(confirm == 'Y' || confirm == 'y')
                {
                    products.erase(products.begin() + index);
                    cout<<"Product deleted successfully!"<<endl;
                }
                else
                {
                    cout<<"Deletion cancelled."<<endl;
                }
            }
            else
            {
                cout<<"Product not found!"<<endl;
            }
        }
        else if(deleteChoice == 2)
        {
            string deleteName;
            cout<<"Enter product name to delete: ";
            cin.ignore();
            getline(cin, deleteName);
            
            int index = findProductbyName(deleteName);
            if(index != -1)
            {
                cout<<"Found product ID: " << products[index].id << endl;
                cout<<"Are you sure you want to delete this product? (Y/N): ";
                char confirm;
                cin>>confirm;
                
                if(confirm == 'Y' || confirm == 'y')
                {
                    products.erase(products.begin() + index);
                    cout<<"Product deleted successfully!"<<endl;
                }
                else
                {
                    cout<<"Deletion cancelled."<<endl;
                }
            }
            else
            {
                cout<<"Product not found!"<<endl;
            }
        }
        else
        {
            cout<<"Invalid option!"<<endl;
        }
    }
    else
    {
        cout<<"Invalid option!"<<endl;
    }
}

struct Supplier
{
    int id;
    string name;
    int phonenumber;
    string email;
};

vector<Supplier> suppliers;

int findSupplierbyID(int id)
{
    for(int i=0; i<suppliers.size(); i++)
    {
        if(suppliers[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void addsupplier(int num)
{
    if(num==1)
    {
        Supplier newsupplier;
        cout<<"Enter supplier ID: "<<endl;
        cin>>newsupplier.id;
        
        cout<<"Enter supplier's name: "<<endl;
        cin>>newsupplier.name;

        cout<<"Enter supplier's phone number: "<<endl;
        cin>>newsupplier.phonenumber;

        cout<<"Enter supplier's email: "<<endl;
        cin>>newsupplier.email;

        suppliers.push_back(newsupplier);
    }
    else if(num==2)
    {
        if(products.empty())
        {
            cout<<"No product available!"<<endl;
        }
        else
        {
            cout<<"Available products: "<<endl;    
            for(int i=0;i<products.size();i++)
            {
                cout<<"Product name: "<<products[i].name<<"    Product ID: "<<products[i].id<<endl;
            }
        }    

        if(suppliers.empty())
        {
            cout<<"No supplier available!"<<endl;
        }
        else
        {
            cout<<"Available suppliers: "<<endl;    
            for(int i=0;i<suppliers.size();i++)
            {
                cout<<"Supplier name: "<<suppliers[i].name<<"    Supplier ID: "<<suppliers[i].id<<endl;
            }
        }    

        int pid;
        cout<<"Enter product ID that you want to link to the supplier: "<<endl;
        cin>>pid;
        
        int sid;
        cout<<"Enter supplier ID that you want to link to the product: "<<endl;
        cin>>sid;

        int pindex;
        bool flag=false;
        for(int i=0;i<products.size();i++)
        {
            if(products[i].id==pid)
            {
                pindex=i;
                flag=true;
                break;
            }
        }
        if(flag!=true)
        {
            cout<<"No product found!"<<endl;
            return;
        }

        bool found=false;
        for(int i=0;i<suppliers.size();i++)
        {
            if(suppliers[i].id==sid)
            {
                products[pindex].supplierID=sid;        
                cout<<"Product linked to supplier successfully!"<<endl;
                found=true;
            }
        }
        if(found!=true)
        {
            cout<<"No supplier found!"<<endl;
        }
    }
    else if(num==3)
    {
        for(int i=0;i<suppliers.size();i++)
        {
            cout<<"Supplier's ID: "<<suppliers[i].id<<endl;
            cout<<"Supplier's name: "<<suppliers[i].name<<endl;
            cout<<"Supplier's phone number: "<<suppliers[i].phonenumber<<endl;
            cout<<"Supplier's email: "<<suppliers[i].email<<endl;
        }
    }
    else if(num==4)
    {
        int deleteSupplierID;
        cout<<"Enter supplier ID to delete: ";
        cin>>deleteSupplierID;
        
        int index = findSupplierbyID(deleteSupplierID);
        if(index != -1)
        {
            bool hasLinkedProducts = false;
            for(int i=0; i<products.size(); i++)
            {
                if(products[i].supplierID == deleteSupplierID)
                {
                    hasLinkedProducts = true;
                    break;
                }
            }
            
            if(hasLinkedProducts)
            {
                cout<<"Cannot delete supplier! " << suppliers[index].name;
                cout<<" has products linked to it."<<endl;
                cout<<"First update or delete those products."<<endl;
            }
            else
            {
                cout<<"Found supplier: " << suppliers[index].name << endl;
                cout<<"Are you sure you want to delete this supplier? (Y/N): ";
                char confirm;
                cin>>confirm;
                
                if(confirm == 'Y' || confirm == 'y')
                {
                    suppliers.erase(suppliers.begin() + index);
                    cout<<"Supplier deleted successfully!"<<endl;
                }
                else
                {
                    cout<<"Deletion cancelled."<<endl;
                }
            }
        }
        else
        {
            cout<<"Supplier not found!"<<endl;
        }
    }
    else
    {
        cout<<"Invalid option!"<<endl;
    }
}

struct SaleItem {
    int productID;
    string productName;
    int quantity;
    double unitPrice;
    double itemTotal; 
};

struct Sale {
    int saleID;
    string customerName;
    vector<SaleItem> items; 
    double grandTotal;
    string date; 
};

vector<Sale> sales;

int findSalebyID(int saleID)
{
    for(int i=0; i<sales.size(); i++)
    {
        if(sales[i].saleID == saleID)
        {
            return i;
        }
    }
    return -1;
}

void saleprocessing(int num)
{
    if(num==1)
    {
        Sale newsale;

        cout<<"Enter Customer name: "<<endl;
        cin.ignore();
        getline(cin,newsale.customerName);

        cout<<"Enter sale ID: "<<endl;
        cin>>newsale.saleID;

        cout<<"Enter date (DD/MM/YYYY): "<<endl;
        cin.ignore();
        getline(cin, newsale.date);

        bool flag=false;
        while(flag!=true)
        {
            int pid;
            cout<<"Enter product ID: "<<endl;
            cin>>pid;

            int prodindex=-1;
            for(int i=0;i<products.size();i++)
            {
                if(products[i].id==pid)
                {
                    cout<<"Product exists!"<<endl;

                    prodindex=i;
                    break;
                }
            }

            if(prodindex==-1)
            {
                cout<<"Product not found!"<<endl;
                continue;
            }
            int quan;
            cout<<"Enter the quantity: "<<endl;
            cin>>quan;

            if(quan<=0)
            {
                cout<<"Invalid quantity!"<<endl;
            }
            else if(products[prodindex].quantity<quan)
            {
                cout<<"Not enough stock!"<<endl;
                continue;
            }

            SaleItem newitem;
            newitem.productID=pid;
            newitem.productName=products[prodindex].name;
            newitem.quantity=quan;
            newitem.unitPrice=products[prodindex].price;
            newitem.itemTotal=quan*products[prodindex].price;
            
            newsale.items.push_back(newitem);

            products[prodindex].quantity-=quan;

            string response;
            cout<<"Want to add another product? (Y(yes) or N(no))"<<endl;
            cin.ignore();
            getline(cin,response);
            if(response=="N" || response=="n")
            {
                newsale.grandTotal=0;
                for(int i=0;i<newsale.items.size();i++)
                {
                    newsale.grandTotal+=newsale.items[i].itemTotal;
                }

                cout<<"=== Reciept==="<<endl;
                cout<<"Customer: "<<newsale.customerName<<endl;
                cout<<"Sale ID: "<<newsale.saleID<<endl;
                cout<<"Items: "<<endl;

                for(int i=0;i<newsale.items.size();i++)
                {
                    cout<<newsale.items[i].productName<<" x "<<
                    newsale.items[i].quantity<<"= "<<
                    newsale.items[i].itemTotal<<endl;
                }
                cout<<"Grand Total: "<<newsale.grandTotal<<endl;

                sales.push_back(newsale);
                cout<<"Sale recorded successfully!"<<endl;
                flag=true;
            }
            else
            {
                continue;
            }
        }
    }
    else if(num==2)
    {
        if(sales.empty())
        {
            cout<<"No sales available!"<<endl;
            return;
        }

        for(int i=0;i<sales.size();i++)
        {
            cout<<"Sale ID: "<<sales[i].saleID<<endl;
            cout<<"Customer name: "<<sales[i].customerName<<endl;
            cout<<"Date: "<<sales[i].date<<endl;
            cout<<"Grand Total: "<<sales[i].grandTotal<<endl;
            
            cout<<"=== PRODUCTS PURCHASED ==="<<endl;
            for(int j=0;j<sales[i].items.size();j++)
            {
                cout<<"Product Name: "<<sales[i].items[j].productName<<endl;
                cout<<"Product ID: "<<sales[i].items[j].productID<<endl;
                cout<<"Product Quantity: "<<sales[i].items[j].quantity<<endl;
                cout<<"Product Price: "<<sales[i].items[j].unitPrice<<endl;
                cout<<"Total Products Price: "<<sales[i].items[j].itemTotal<<endl;
            }
        }
    }
    else if(num==3)
    {
        int deleteSaleID;
        cout<<"Enter sale ID to delete: ";
        cin>>deleteSaleID;
        
        int index = findSalebyID(deleteSaleID);
        if(index != -1)
        {
            for(int i=0; i<sales[index].items.size(); i++)
            {
                int productID = sales[index].items[i].productID;
                int quantitySold = sales[index].items[i].quantity;
                
                for(int j=0; j<products.size(); j++)
                {
                    if(products[j].id == productID)
                    {
                        products[j].quantity += quantitySold;
                        break;
                    }
                }
            }
            
            cout<<"Found sale for customer: " << sales[index].customerName << endl;
            cout<<"Total amount: $" << sales[index].grandTotal << endl;
            cout<<"Are you sure you want to delete this sale? (Y/N): ";
            char confirm;
            cin>>confirm;
            
            if(confirm == 'Y' || confirm == 'y')
            {
                sales.erase(sales.begin() + index);
                cout<<"Sale deleted successfully! Product quantities restored."<<endl;
            }
            else
            {
                for(int i=0; i<sales[index].items.size(); i++)
                {
                    int productID = sales[index].items[i].productID;
                    int quantitySold = sales[index].items[i].quantity;
                    
                    for(int j=0; j<products.size(); j++)
                    {
                        if(products[j].id == productID)
                        {
                            products[j].quantity -= quantitySold;
                            break;
                        }
                    }
                }
                cout<<"Deletion cancelled."<<endl;
            }
        }
        else
        {
            cout<<"Sale not found!"<<endl;
        }
    }
    else
    {
        cout<<"Invalid option!"<<endl;
    }

}

int main()
{
    int opt;
    do
    {       
        cout<<"Menu"<<endl;
        cout<<endl;
        cout<<"(1.) Product Management"<<endl;
        cout<<"(2.) Supplier Management"<<endl;
        cout<<"(3.) Sales And Transaction Processing"<<endl;
        cout<<"(4.) Exit"<<endl;
        cout<<"Enter the option (1-4): "<<endl;
        cin>>opt;
        
        if(opt==1)
        {
            cout<<"(1.) Add product"<<endl;
            cout<<"(2.) Update product information"<<endl;
            cout<<"(3.) Search for products"<<endl;
            cout<<"(4.) View all products"<<endl;
            cout<<"(5.) Check low stock"<<endl;
            cout<<"(6.) Delete product"<<endl;

            int opt1;
            cout<<"Enter the option (1-6): "<<endl;
            cin>>opt1;

            if(opt1==1)
            {
                addproduct(opt1);
            }
            else if(opt1==2)
            {
                addproduct(opt1);
            }
            else if(opt1==3)
            {
                addproduct(opt1);
            }
            else if(opt1==4)
            {
                addproduct(opt1);
            }
            else if(opt1==5)
            {
                addproduct(opt1);
            }
            else if(opt1==6)
            {
                addproduct(opt1);
            }
            else
            {
                cout<<"Invalid option!"<<endl;
            }
            
        }
        else if(opt==2)
        {
            cout<<"(1.) Add A New Supplier"<<endl;
            cout<<"(2.) Link Products To Suppliers"<<endl;
            cout<<"(3.) View Supplier Directory"<<endl;
            cout<<"(4.) Delete Supplier"<<endl;
            
            int opt2;
            cout<<"Enter the option (1-4): "<<endl;
            cin>>opt2;
            if(opt2==1)
            {
                addsupplier(opt2);
            }
            else if(opt2==2)
            {
                addsupplier(opt2);
            }
            else if(opt2==3)
            {
                addsupplier(opt2);
            }
            else if(opt2==4)
            {
                addsupplier(opt2);
            }
            else
            {
                cout<<"Invalid option!"<<endl;
            }
        }
        else if(opt==3)
        {
            cout<<"(1.) Process A New Sale"<<endl;
            cout<<"(2.) View Sales History"<<endl;
            cout<<"(3.) Delete Sale"<<endl;
            int opt3;
            cout<<"Enter the option (1-3): "<<endl;
            cin>>opt3;

            if(opt3==1)
            {
                saleprocessing(opt3);
            }
            else if(opt3==2)
            {
                saleprocessing(opt3);
            }
            else if(opt3==3)
            {
                saleprocessing(opt3);
            }
            else
            {
                cout<<"Invalid option!"<<endl;
            }

        }
        else
        {
            cout<<"Invalid Option!";
        }
    }while(opt!=4);

    cout<<"Thankyou for using TAHA'S Inventory And Sales Tracker!"<<endl;
}