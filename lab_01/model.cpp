#include "model.h"

err_t load_model(model_t &model, const char *filename)
{
    err_t rc = SUCCESS;

    if (filename == NULL)
        rc = FILE_NAME_ERROR;
    else
    {
        FILE *file = fopen(filename, "r");
        if (file == NULL)
            rc = FILE_OPEN_ERROR;
        else
        {
            rc = read_model(model, file);
            if (rc)
                free_model(model);
            fclose(file);
        }
    }

    return rc;
}

err_t read_model(model_t &model, FILE *file)
{
    err_t rc = SUCCESS;

    model.center.x = 0;
    model.center.y = 0;
    model.center.z = 0;

    if (file == NULL)
        rc = FILE_OPEN_ERROR;
    else
    {
        rc = read_all_points(model.points, file);
        if (! rc)
        {
            rc = read_all_facets(model.facets, file);
            if (rc)
                free_array_of_points(model.points);
        }
    }

    return rc;
}

void free_model(model_t &model)
{
    free_array_of_points(model.points);
    free_array_of_facets(model.facets);
}

err_t transfer_model(model_t &model, const transfer_t &transfer)
{
    transfer_point(model.center, transfer);
    err_t rc = transfer_all_points(model.points, transfer);

    return rc;
}

err_t scale_model(model_t &model, const scale_t &scale)
{
    err_t rc = scale_all_points(model.points, model.center, scale);
    return rc;
}

err_t turn_model(model_t &model, const turn_t &turn)
{
    err_t rc = turn_all_points(model.points, model.center, turn);
    return rc;
}

void delete_model(model_t &model)
{
    free_array_of_points(model.points);
    free_array_of_facets(model.facets);
}
