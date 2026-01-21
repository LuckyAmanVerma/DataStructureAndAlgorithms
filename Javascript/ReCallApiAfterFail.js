async function retryApi(fn, time, retries = 3) {
  try {
    return await fn();
  } catch (error) {
    if (retries === 0) {
      throw error;
    }

    console.log(`Retrying... attempts left: ${retries}`);

    await new Promise(resolve => setTimeout(resolve, time));

    return retryApi(fn, time, retries - 1);
  }
}
