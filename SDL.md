# Kan Scene Description Language

Kan reads scene data from a YAML file.

## Value Types

- **point**  
  A `point` represents a location in 3D space. It is a 3-element YAML array.
- **vector**  
  A `vector` represents a direction in 3D space. It is a 3-element YAML array.
  > [!TIP] Kan will normalize all vectors that should be unit length. You, as
  > the scene writer, do not need to manually normalize any vectors.
- **range**  
  A `range` represents a set of values that an element can take. It is a
  2-element YAML array.

## `scene`

The scene file must contain exactly one `scene` element. The `scene` is a YAML
object.

### `scene.camera`

The `scene` must contain exactly one `camera` element. The `camera` sets up the
view of the scene.

#### `scene.camera.position`

- **Type:** Array of three numbers
- **Default Value:** `[0, 0, 0]`

The `camera`'s `position` element sets the position of the camera in the scene.

#### `scene.camera.look-at`

- **Type:** Array of three numbers
- **Default Value:** `[0, 0, -1]`

The `camera`'s `look-at` element sets the point in space that the camera looks
at.

#### `scene.camera.up`

- **Type:** Array of three numbers
- **Default Value:** `[0, 1, 0]`

The `camera`'s `up` vector orients the camera in space.

> [!WARNING] > `camera.position` and `camera.look-at` are points in space.
> `camera.up` is a vector.
