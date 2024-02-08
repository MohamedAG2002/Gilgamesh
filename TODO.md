# Short-Term TODO:
- Shader manager
- Make uniform buffers part of the shader instead of a stand-alone thing
- Uniform buffers starting size and automatic configurations of the layout just like the pointer attributes
- Materials
- Meshes: Creating them, managing the, rendering them, and etc...
- Design an instanced renderer?!!!

# Things to fix or make better 
- Vertex arrays. Just everything. Refactor everything in it
- Probably have begin_renderer a scene object or something like that instead of render_data
- The memory_alloc files probably need to be changed because the C-style way of allocating data doesn't take dynamically sized types. Either overload 'new' and 'delete' and deal with that or find a way to combat that issue.

# Mid-Term TODO:
- Slowly remove STL from the engine. Completely!
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
