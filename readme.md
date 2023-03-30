Setup& configurations using eosio official document

Create Developement Wallet
	Cleos wallet create –to-console
PW5KZnKSTnHSQduiYbvx3AdpfEJjSf8StSTE1izMPhHYJzT6XwTCz


	cleos wallet create -n coding-tutorial --file tutorial_passowrd.txt            
	cleos wallet open -n coding-tutorial
	cleos wallet unlock -n coding-tutorial
	cleos wallet create_key -n coding-tutorial
> EOS62dtUasJZtDXQcH38yLZSmvKgFFkQj2hKTyaLXLHuywayZVzgC
	cleos wallet import -n coding-tutorial



****** Compiling & Uploading the smartcontract ********

eosio-cpp tutorial.cpp -o codetutorial.wasm --abigen
