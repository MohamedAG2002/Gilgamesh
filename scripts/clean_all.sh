echo "Cleaning engine..."
cd ../build/ 
rm -rf *
cd ../scripts/

echo "Cleaning tests..."
cd ../apps/build/ 
rm -rf * 
cd ../../scripts/

echo "Clean complete..."
