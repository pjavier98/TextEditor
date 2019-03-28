UTILITIES = utilities/header.h
SEARCH = searchAlgorithm/search.h searchAlgorithm/search.cpp
AUTOCOMPLETE = autocompleteAlgorithm/autocomplete.h autocompleteAlgorithm/autocomplete.cpp
BADNESS = badnessAlgorithm/badness.h badnessAlgorithm/badness.cpp
TEXT_EDITOR = textEditor.cpp

make compile_text_editor:
	g++ -std=c++17 $(UTILITIES) $(SEARCH) $(AUTOCOMPLETE) $(BADNESS) $(TEXT_EDITOR) -o text
