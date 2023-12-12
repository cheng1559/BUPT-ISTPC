echo [INFO]: Building problem 'r10-path-huaguang'.
pushd problems\r10-path-huaguang
call doall.bat
popd

echo [INFO]: Building problem 'r10-fontaine-whale'.
pushd problems\r10-fontaine-whale
call doall.bat
popd

echo [INFO]: Building problem 'r10-sacred-sakura-cleansing-ritual'.
pushd problems\r10-sacred-sakura-cleansing-ritual
call doall.bat
popd

echo [INFO]: Building problem 'r10-cat-tail'.
pushd problems\r10-cat-tail
call doall.bat
popd

echo [INFO]: Building problem 'r10-shortest-path'.
pushd problems\r10-shortest-path
call doall.bat
popd

echo [INFO]: Building chinese contest statement.
pushd statements\chinese
call doall.bat
popd

echo [INFO]: Building english contest statement.
pushd statements\english
call doall.bat
popd

