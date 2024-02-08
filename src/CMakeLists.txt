add_executable(Ants
        main.cpp
        Environment.h
        Environment.cpp
        MathUtils.h
        Rectangle.h
        Renderer.h
        Renderer.cpp
        Timer.h
        Timer.cpp
        Vector2.h
        Agent.h Agent.cpp Food.cpp Food.h Anthill.cpp Anthill.h AntBase.cpp AntBase.h SillyAnt.cpp SillyAnt.h Pheromone.cpp Pheromone.h AntBasePheromone.cpp AntBasePheromone.h Ant.cpp Ant.h AbstractRule.cpp AbstractRule.h OrRule.cpp OrRule.h AbstractAntRule.cpp AbstractAntRule.h AntWithRules.cpp AntWithRules.h)

target_link_libraries(Ants Threads::Threads SDL2::Main SDL2::GFX)