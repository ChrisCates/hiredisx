lcov --directory . --capture --output-file tests.coverage
bash <(curl -s https://codecov.io/bash) -t 7f531b12-f29b-44d6-98c6-22ad5d214702
