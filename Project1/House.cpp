// House.cpp

float square(int x) {
    return x * x;
}

int ceil(float x) {

    if (x == int(x))
        return x;
    else
        return x+1;

}

bool iseven(int x) {
    if (int(x/2) == float(x)/2)
        return true;
    else
        return false;
}

bool House::checksize(int size) {
        if (size < 4 || size > 37)
            return false;
        else
            return true;
}

bool House::check_ascii(int val) { // Double Check This
        if (int(val) < 33 || int(val) > 126)
            return false;
        else
            return true;
    }

    // Add methods to detect out of bounds size
House::House(int size, char border='X', char fill='*'){
        this->size = checksize(size)? size: 4; // default to minimum size
        this->border = border;
        this->fill = fill; 
    }

int House::GetSize() {
        return this->size;
    }

int House::Perimeter() {
        return this->size * 2  + (this->size + 2) * 3;
    }

    // review this later
float House::Area() {
        float sqarea =  square(this->size ) ;
        float triangle_area =  (float)1/2  * sqarea * 0.86602540378;
        
        return (float) sqarea + triangle_area;
    }

void House::Grow() {
        checksize(this->size+1) ? this->size++ : this->size; // Check if size goes out of bounds
    }

void House::Shrink() {
        checksize(this->size-1) ? this->size-- : this->size;
}

    // SetBorder
void House::SetBorder(int AsciiChar) {
        if (check_ascii(AsciiChar))
            this->border = toascii(AsciiChar);
        
    }
    
    // Set the fill
void House::SetFill(int AsciiChar) {
    if (check_ascii(AsciiChar))
        this->fill = toascii(AsciiChar);
    }
    
    // Draw
void House::Draw() {

        std::cout << "Drawing: " << std::endl << "-------------------" << std::endl;

        // Draw the Triangle
        // Draw the first border element
        
        int spc = this->size;
        int diff = 1 - iseven(this->size); // measures deviation form the variation in algorithm due to even/odd error

        for (int i = 0; i <= spc ; i++)
            std::cout << " ";
        std::cout << this->border << std::endl;

        for(int i = 1, k = 0; i <= ceil(this->size /2) + 1 + diff; i++, k = 0)
    {

        for(int space = 1; space <= ceil(this->size/2)-i + 1 + diff; ++space)
        {


        if (i==1 && space==ceil(this->size/2)-i + 1 + diff && diff) // Get rid of extra space
                std::cout << " ";
        else
            std::cout <<"  ";

        }

        // modification
        while(k != 2*i)
        {
            if(k == 0 || k == 2*i-1)
                std::cout << this->border << " ";
            else if (diff && k == 2 *i - 2)
                std::cout << "";
            else
                std::cout << this->fill << " ";
            ++k;
        }
        std::cout <<std:: endl;
    }

    // Draw the square below
        for(int i=1; i<= this->size; ++i) {
            std::cout << "  ";
            for (int j=0; j<this->size; j++) {
             if (j == 0 || j == this->size-1 || i==this->size)
                std::cout << this->border << " ";
            else
                std::cout  << this->fill << " ";
            }
            std::cout << std::endl;
        }
    
    }

void House::Summary() {
        std::cout << "Summary: " << std::endl << "------------" << std::endl;
        std::cout << "Base Size: " << this->size << std::endl;
        std::cout << "Perimeter: " << this->Perimeter() << std::endl;
        std::cout << "Area: " << ceil(this->Area() * 100.0)/100.0 << std::endl << std::endl; // Make this 2 decimal places

        this->Draw();
    }
