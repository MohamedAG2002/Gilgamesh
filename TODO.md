# Short-Term TODO:
- Make the resources as pointers not just copies. But that would have to mean the functions have to take the resources in as pointers not as refs
- Better shader info like having it's path embeded and reading from a single file instead of 2 or more

- Batch renderer
- Design an instanced renderer?!!!
- Materials

# Things to fix or make better 
- Texture numbers. Needs to be set automatically not by the client
- Uniform buffers starting size and automatic configurations of the layout just like the pointer attributes
- Vertex arrays. Just everything. Refactor everything in it
- Probably have begin_renderer a scene object or something like that instead of render_data

# Mid-Term TODO:
- Slowly remove STL from the engine. Completely!
- More sophisticated memory profiler
- File logging
- Cross platform console logging
- Documentation
- Scenes
- Entities
- Serialization
- Audio system -> Basic at first then something more sophisticated

# Long-Term TODO:
- GUI -> Editor gui and game gui
- Scripting system -> Native and external
- Physics
- Particles -> gpu-based and cpu-based 
