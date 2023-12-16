cmake_minimum_required(VERSION 3.23)
project(PokerAnalysis)

set(CMAKE_CXX_STANDARD 14)

add_executable(PokerAnalysis main.cpp Deck.cpp Deck.h Card.cpp Card.h CardHand.cpp CardHand.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h Ranks.h Suits.h SFMLCard.cpp SFMLCard.h Application.cpp Application.h Component.h CardSet.cpp CardSet.h PokerProbability.cpp PokerProbability.h Font.cpp Font.h)


target_link_libraries(PokerAnalysis sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)