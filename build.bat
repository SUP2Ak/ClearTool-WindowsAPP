@echo off
setlocal enabledelayedexpansion

:: Supprimer les fichiers de compilation précédents
@echo "Nettoyage des fichiers de compilation précédents"
del *.obj
del *.pdb
del build/Debug/*
@echo "Nettoyage terminé"

:: Initialiser l'environnement pour MSVC
@echo "Initialisation de l'environnement"
@call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
@echo "Environnement initialisé"

:: Parcourir tous les fichiers .cpp dans le projet
set "files="
for /R %%f in (*.cpp) do (
    set "files=!files! %%f"
)

:: Compiler tous les fichiers trouvés et ajouter le chemin d'inclusion pour les fichiers d'en-tête
cl.exe /Zi /EHsc /I "src/WindowsManager" /Fe:build/Debug/main.exe %files% /link /verbose /out:build/Debug/main.exe user32.lib comctl32.lib gdi32.lib uxtheme.lib

:: Vérifier si le fichier main.exe a été généré
if exist build/Debug/main.exe (
    echo Compilation et linkage réussis !
) else (
    echo Erreur: Le fichier main.exe n'a pas été généré.
)

pause