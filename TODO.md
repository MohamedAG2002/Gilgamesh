# Short-Term TODO:
- Meshes: Don't work for some reason. Renderdoc to the rescue!
- Instanced Renderer
- Lighting
- Materials
- Learn OpenGL

# Things to fix or make better 
- The mesh should take a material and not a texture array
- Vertex arrays. Just everything. Refactor everything in it
- Probably have begin_renderer a scene object or something like that instead of render_data
- The memory_alloc files probably need to be changed because the C-style way of allocating data doesn't take dynamically sized types into account. Either overload 'new' and 'delete' and deal with that or find a way to combat the issue.

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
