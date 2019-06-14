#include <iostream>
#include "bmplib.cpp"
#include <cstring>

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];



void loadImage(){
    char imageFileName[100];
    cout<<"Enter the image file name   : ";
    cin>>imageFileName;
    strcat(imageFileName,".bmp");
    readGSBMP(imageFileName,image);
    cout<<"image loaded !!"<<endl;
}
//___________________________________________
void saveImage(){
    char imageFileName[100];
    cout<<"Enter the image name to save   : ";
    cin>>imageFileName;
    strcat(imageFileName,".bmp");
    writeGSBMP(imageFileName,image);
    cout<<"Image Saved !!!"<<endl;

}//__________________________________________
void invert(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (image[i][j] == 255){
                image[i][j] = 0;
            }else if (image[i][j] == 0){
                image[i][j] = 255;
            }else if (image[i][j] != 255 && image[i][j] != 0){
                image[i][j] = 255 - image[i][j];
            }
        }
    }

}
//___________________________________________
void blackAndWhite(){
    int sum=0;
    int numberOfpixels=0;
    int avarage;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
                sum+=image[i][j];
                numberOfpixels++;
        }
    }
    avarage=sum/numberOfpixels;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
                if(image[i][j]<avarage)
                    image[i][j]= 0;

                else if(image[i][j]>=avarage)
                    image[i][j]= 255;

        }
    }
    cout<<"black and white filter added!"<<endl;

}
//___________________________________________
void Rotate(){
    int choose;

    cout << "What is the angle that you would like to rotate the photo by it: " << endl;
    cout << "Press 1 for 90 degree" << endl;
    cout << "Press 2 for 180 degree" << endl;
    cout << "Press 3 for 270 degree" << endl;

    cin >> choose;
    cout << endl;
    while (choose != 1 && choose != 2 && choose != 3){
        cin.fail();
        cout << "Error, Please enter again" << endl;
        cin >> choose;
    }
    /// for 90 degree
    while (choose == 1){

    for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j < SIZE; j++) {
    swap(image[i][j], image[j][i]);
    }
  }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE / 2; j++){
    swap(image[i][j], image[i][SIZE - j]);
    }
  }
    break;
    }


    /// for 180 degree
  while (choose == 2){

    for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j< SIZE; j++) {
    swap(image[i][j], image[j][i]);
    }
  }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE / 2; j++){
    swap(image[i][j], image[i][SIZE - j]);
    }
  }
  for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j< SIZE; j++) {
    swap(image[i][j], image[j][i]);
    }
  }
  for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE / 2; j++){
    swap(image[i][j], image[i][SIZE - j]);
    }
  }
    break;
  }
  /// for 270 degree
  while (choose == 3){

    for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j< SIZE; j++) {
    swap(image[i][j], image[j][i]);
    }
  }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE / 2; j++){
    swap(image[i][j], image[i][SIZE - j]);
    }
  }
  for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j< SIZE; j++) {
    swap(image[i][j], image[j][i]);
    }
  }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE / 2; j++){
    swap(image[i][j], image[i][SIZE - j]);
    }
  }
  for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j< SIZE; j++) {
    swap(image[i][j], image[j][i]);
    }
  }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE / 2; j++){
    swap(image[i][j], image[i][SIZE - j]);
    }
  }
    break;
  }



}
//___________________________________________
void flipImage(){
    unsigned char lowerMatrix[SIZE][SIZE];
    unsigned char upperMatrix[SIZE][SIZE];
    int choice;
    int flipI=255;
    int flipJ=255;
    char tempTop,tempBot,tempLeft,tempRight;
    cout<<"press 1 for horizontal , 2 for vertical : ";
    cin>>choice;
    if(choice==1){
        for(int i = 0;i<SIZE/2;i++){
            for(int j = 0;j<SIZE;j++){
                tempTop=image[i][j] ;
                tempBot=image[SIZE-i][j];
                image[i][j]=tempBot;
                image[SIZE-i][j]=tempTop;

            }
        }
    }
    else if(choice==2){
        for(int i =0;i<SIZE;i++){
            for(int j = 0;j<SIZE/2;j++){
                tempLeft=image[i][j];
                tempRight=image[i][SIZE-j];
                image[i][j]=tempRight;
                image[i][SIZE-j]=tempLeft;
            }
        }
    }
    else{
        cout<<"invalid input!"<<endl;
    }
}
//___________________________________________
void detectEdges(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if((image[i][j]>image[i][j+1]+40) || (image[i][j]>image[i][j-1]+40) || (image[i][j]>image[i+1][j]+40)|| (image[i][j]>image[i-1][j]+40)){
                image[i][j]=0;
            }else{
                image[i][j]=255;
            }
        }
    }
}
//___________________________________________
void Enlarge(){
    int choose;

    cout << "What is the quartile that you would like to zoom the photo to it: " << endl;
    cout << "Press 1 for Q1" << endl;
    cout << "Press 2 for Q2" << endl;
    cout << "Press 3 for Q3" << endl;
    cout << "Press 4 for Q4" << endl;

    cin >> choose;
    cout << endl;
    cout << endl;
    while (choose != 1 && choose != 2 && choose != 3 && choose != 4){
        cin.fail();
        cout << "Error, Please enter again" << endl;
        cin >> choose;
    }
    //    Q1
    while (choose == 1){
        for (int i = 0 , k = 0 ; i <= 128 ; i++ , k+=2){
            for (int j = 0 , l = 0 ; j <= 128 ; j++ , l+=2){
                image2[k][l] = image[i][j];
            }
        }
        break;
    }
        // Q3
    while (choose == 3){
        for (int i = 128 , k = 0; i <= 256; i++ , k+=2){
            for (int j = 0 , l = 0 ; j <= 128 ; j++ , l+=2){
                image2[k][l] = image[i][j];
            }
        }
        break;
    }
        // Q4
    while (choose == 4){
        for (int i = 128 , k = 0; i <= 256; i++ , k+=2){
            for (int j = 128 , l = 0 ; j <= 256 ; j++ , l+=2){
                image2[k][l] = image[i][j];
            }
        }
        break;
    }
        // Q2
    while (choose == 2){
        for (int i = 0 , k = 0; i <= 128; i++ , k+=2){
            for (int j = 128 , l = 0 ; j <= 256 ; j++ , l+=2){
                image2[k][l] = image[i][j];
            }
        }
        break;
    }


        //2l LOOP 3SHAN TSL7 2L SAVE :D :-
        for(int i=0 ; i<SIZE; i++){
            for(int j=0 ; j<SIZE ; j++){
                    image[i][j]=image2[i][j];
            }
        }





}
//___________________________________________

void imageMirror(){
    int choice;
    cout<<"press 1 for leftHalf \n";
    cout<<"press 2 for rightHalf \n";
    cout<<"press 3 for upperHalf \n";
    cout<<"press 4 for lowerHalf \n";
    cin>>choice;
    if(choice==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                image[i][SIZE-j]=image[i][j];
            }
        }

    }
    if(choice==2){
        for(int i =0;i<SIZE;i++){
            for(int j =0;j<SIZE;j++){
                image[i][j]=image[i][SIZE-j];
            }
        }
    }
    if(choice==3){
        for(int i =0;i<SIZE;i++){
            for(int j = 0;j<SIZE;j++){
                image[SIZE-i][j]=image[i][j];
            }
        }
    }
    if(choice==4){
        for(int i =0;i<SIZE;i++){
            for(int j = 0;j<SIZE;j++){
                image[i][j]=image[SIZE-i][j];
            }
        }
    }

}
void shuffel(){





}






//___________________________________________
int main()
{
    int choice;
    cout<<"ahlan ya user ya habibi"<<endl;
    while(true){

        cout<<"press 1 to load image"<<endl;
        cout<<"press 2 to apply black and white filters"<<endl;
        cout<<"press 3 to invert the image "<<endl;
        cout<<"press 4 to apply merge filter "<<endl;
        cout<<"press 5 to flip image"<<endl;
        cout<<"press 6 to darken and lighten image"<<endl;
        cout<<"press 7 to rotate image"<<endl;
        cout<<"press 8 to detect image edges"<<endl;
        cout<<"press 9 to Enlarge image"<<endl;
        cout<<"press 10 to shrink image"<<endl;
        cout<<"press 11 to save image to a file "<<endl;
        cout<<"press 12 to get the mirror of the image"<<endl;
        cout<<"press 13 to shuffel the image"<<endl;
        cout<<"press 0 to Exit"<<endl;
        cin>>choice;


        if(choice==1){
            loadImage();
        }
        else if(choice==2){
            blackAndWhite();
        }
        else if(choice==3){
            invert();
        }
        else if(choice==5){
            flipImage();
        }
        else if(choice==7){
            Rotate();
        }
        else if(choice==8){
            detectEdges();
        }
        else if(choice==9){
            Enlarge();
        }
        else if(choice==11){
            saveImage();
        }
        else if(choice==12){
            imageMirror();
        }
        else if(choice==13){
            shuffel();
        }
        else if(choice==0){
            cout<<"ta3ala kol yom"<<endl;
            return 0;
        }
        else{
            cout<<"invalid choice, Please pick another one"<<endl;
        }

    }
}
